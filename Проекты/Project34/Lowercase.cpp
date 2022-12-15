#include "Lowercase.h"

void Lowercase::push(wstring word) {
	if (!iswupper(word[0])) {
		v.push_back(word);
	}
}