#pragma once
#include "Word.h"

class Uppercase : public Word
{
public:
	Uppercase() {}
	virtual void push(wstring word);
};