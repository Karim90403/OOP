#include "DB.h"

struct Leaks {
    ~Leaks() { _CrtDumpMemoryLeaks(); }
};
Leaks _l;

int wmain(int argc, wchar_t* argv[]) {

    srand(time(NULL));

    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

    wifstream input("OOP.txt");

    input.imbue(locale(input.getloc(), new codecvt_utf8<wchar_t, 0x10ffff, consume_header>));

    vector<wstring> v;
    wstring word;
    while (!input.eof()) {
        getline(input, word);
        word.push_back('\n');
        v.push_back(word);
    }

    int end = v.size() / 2;

    DB<Muzafarov*> db1, db2;

    //db2.push_back(new Muzafarov);

    db1.fill(v, end);

    db2 = db1;

    db2.cleanData();
    db2.print();


    wcout << endl;
}