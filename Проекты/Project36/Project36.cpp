#include "PolyLineShape.h"

struct Leaks {
	~Leaks() {
		_CrtDumpMemoryLeaks();
	}
};
Leaks _l;

int main()
{
	vector <Shape*> DB;
	char reader;
	string words, word;
	ifstream in("File.hpgl");

	while (!in.eof()) {
		in >> word;
		words += (word);
	}

	vector<int> x;
	vector<int> y;
	string sx, sy;
	int pointsNum = 0, checker = 0, CheckX = 0, CheckY = 0;
	for (int i = 45; i < words.size(); i++) {
		if (words[i - 1] == 'P' && words[i] == 'U') {
			if (checker == 0) {
				checker = 1;
				pointsNum = 0;
				continue;
			}
			else if (checker == 1) {
				if (pointsNum <= 2) {
					DB.push_back(new LineShape(x, y));
				}
				else {
					DB.push_back(new PolyLineShape(x, y));
				}
				x.clear();
				y.clear();
				pointsNum = 0;
				checker = 1;
			}
			continue;
		}
		if (checker == 1 && words[i] == 'D' && words[i - 1] == 'P') {
			continue;
		}
		if (words[i] == 'A' && words[i - 1] == 'P') {
			CheckX = 1;
			continue;
		}
		if (CheckX == 1 && words[i] >= '0' && words[i] <= '9') {
			sx = sx + words[i];
		}
		else if (words[i] == ',') {
			int unstringify;
			unstringify = atoi(sx.c_str());
			sx = "";
			x.push_back(unstringify);
			unstringify = 0;
			CheckX = 0;
			CheckY = 1;
			continue;
		}
		if (CheckY == 1 && words[i] >= '0' && words[i] <= '9') {
			sy = sy + words[i];
		}
		else if (words[i] == ';' && sy != "") {
			int unstringify;
			unstringify = atoi(sy.c_str());
			sy = "";
			y.push_back(unstringify);
			unstringify = 0;
			CheckY = 0;
			CheckX = 1;
			pointsNum++;
		}
	}
	for (int i = 0; i < DB.size(); i++) {
		delete DB[i];
		DB[i] = 0;
	}
}
