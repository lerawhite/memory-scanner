#pragma once
#include <windows.h>

struct memory_region
{
	void* adr;
	SIZE_T reg_size;
	DWORD state;
	DWORD protect;
	DWORD type;
};