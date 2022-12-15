#pragma once
#include "Word.h"

class Lowercase : public Word
{
public:
	Lowercase() {}
	virtual void push(wstring word);
};