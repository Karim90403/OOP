#include "Uppercase.h"
void Uppercase::push(wstring word) {
	if (iswupper(word[0])) {
		v.push_back(word);
	}
}