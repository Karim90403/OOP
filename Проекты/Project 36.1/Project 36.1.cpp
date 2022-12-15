#include "Project 36.1.h"
#include <windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR WinName[] = _T("MainFrame");

vector <Shape*> DB;
ofstream out;
string words, new_words;

int APIENTRY WinMain(HINSTANCE This, HINSTANCE Prev, LPSTR cmd, int mode)
{
    HWND hWnd;
    MSG msg;
    WNDCLASS wc;
    wc.hInstance = This;
    wc.lpszClassName = WinName;
    wc.lpfnWndProc = WndProc;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszMenuName = NULL;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    if (!RegisterClass(&wc)) return 0;
    hWnd = CreateWindow(WinName, _T("Каркас Windows-приложения"),
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        CW_USEDEFAULT, HWND_DESKTOP, NULL, This, NULL);
    ShowWindow(hWnd, mode);

	char reader;
	string word;
	ifstream in("input.hpgl");

	while (!in.eof()) {
		in >> words;
		word += (words);
	}

	vector<int> x;
	vector<int> y;
	string stringx, stringy;
	int pointsNum = 0, checker = 0, CheckX = 0, CheckY = 0;
	for (int i = 45; i < word.size(); i++) {
		if (word[i - 1] == 'P' && word[i] == 'U') {
			if (checker == 0) {
				checker = 1;
				pointsNum = 0;
				continue;
			}
			else if (checker == 1) {
				if (pointsNum <= 2) {
					DB.push_back( new LineShape(x, y));
				}
				else {
					DB.push_back( new PolyLineShape(x, y));
				}
				x.clear();
				y.clear();
				pointsNum = 0;
				checker = 1;
			}
			continue;
		}
		if (checker == 1 && word[i] == 'D' && word[i - 1] == 'P') {
			continue;
		}
		if (word[i] == 'A' && word[i - 1] == 'P') {
			CheckX = 1;
			continue;
		}
		if (CheckX == 1 && word[i] >= '0' && word[i] <= '9') {
			stringx = stringx + word[i];
		}
		else if (word[i] == ',') {
			int unstringify;
			unstringify = atoi(stringx.c_str());
			stringx = "";
			x.push_back(unstringify);
			unstringify = 0;
			CheckX = 0;
			CheckY = 1;
			continue;
		}
		if (CheckY == 1 && word[i] >= '0' && word[i] <= '9') {
			stringy = stringy + word[i];
		}
		else if (word[i] == ';' && stringy != "") {
			int unstringify;
			unstringify = atoi(stringy.c_str());
			stringy = "";
			y.push_back(unstringify);
			unstringify = 0;
			CheckY = 0;
			CheckX = 1;
			pointsNum++;
		}
	}


    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam,
    LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
	static int sx, sy;
    int x, y;
    HPEN hpen1 = CreatePen(PS_SOLID, 2, RGB(0, 166, 166));
    switch (message)
    {
    case WM_SIZE:
        sx = LOWORD(lParam);
        sy = HIWORD(lParam);
        break;
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        SelectObject(hdc, hpen1);

        for (int i = 0; i < DB.size(); i++)
			DB[i] -> print(&hdc, sx, sy);

		for (int i = 0; i < 45; i++)
			new_words += words[i];

		for (int i = 0; i < DB.size(); i++)
		{
			new_words += "PU;";
			for (int j = 0; j < DB[i] -> v.size(); j++)
			{
				new_words += "PA";
				new_words += to_string(DB[i] -> v[j].x);
				new_words += ',';
				new_words += to_string(DB[i] -> v[j].y);
				new_words += ";PD;";
			}
		}

		new_words += "PU;PA0,0;SP;";

		out.open("output.hpgl");
		if (out.is_open())
		{
			out << new_words;
		}
		out.close();

        DeleteObject(hpen1);
        EndPaint(hWnd, &ps);
        break;
    case WM_DESTROY:PostQuitMessage(0);
        break;
    default:return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
