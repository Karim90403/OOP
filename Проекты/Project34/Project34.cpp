#include "Lowercase.h"
#include "Uppercase.h"

struct Leaks {
    ~Leaks() { _CrtDumpMemoryLeaks(); }
};
Leaks _l;

int wmain(int argc, wchar_t* argv[]) {

    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

    Uppercase uppercase;
    Word words;

    wifstream input("file.txt");
    wofstream output("output.txt");

    output.imbue(locale(output.getloc(), new codecvt_utf8<wchar_t, 0x10ffff, consume_header>));
    input.imbue(locale(input.getloc(), new codecvt_utf8<wchar_t, 0x10ffff, consume_header>));

    wstring word;

    while (!input.eof()) {
        input >> word;
        if (word[word.length() - 1] == L'.' || word[word.length() - 1] == L',') {
            word.erase(word.length() - 1);
        }
        words.push(word);
    }

    for (wstring word : words.v)
        uppercase.push(word);

    for (wstring word : uppercase.v)
        output << word << endl;

    wcout << endl;
}