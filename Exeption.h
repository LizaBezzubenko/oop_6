#pragma once
#include <string>


class myExep {
	char nameExep[40];
public:
	myExep() { strcpy_s(nameExep, 0); }
	myExep(const char* str) { strcpy_s(nameExep, str); }
	~myExep() = default;
	char* ShowExepName() { return nameExep; }
};