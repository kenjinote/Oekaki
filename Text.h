#pragma once
#include "Object.h"

class Text :
	public Object
{
public:
	Text();
	~Text();
private:
	LPWSTR lpszText;

};

