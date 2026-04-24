#pragma once
#include <windows.h>

class uniquehandle
{
	HANDLE handle;

public:
	uniquehandle(HANDLE h);
	~uniquehandle();
	HANDLE get() const;
};