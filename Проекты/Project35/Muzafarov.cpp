#include "Muzafarov.h"

void Muzafarov::push(vector<wstring>& v, int start, int end) {
	for (int i = start; i < end; i++) {
		m_txt.push_back(v[i]);
	}
}

Muzafarov* Muzafarov::copy() {
	return new Muzafarov(*this); 
}

void Muzafarov::print() {
	for (int i = 0; i < m_txt.size(); i++) {
		wcout << m_txt[i];
	}
}

string Muzafarov::checkClass()
{
	return "Muzafarov";
}