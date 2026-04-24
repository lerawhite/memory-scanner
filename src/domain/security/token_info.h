#pragma once
#include <iostream>
#include <windows.h>

struct token_info
{
	DWORD pid;
	std::string SID;
	std::string IL;
	bool result;
};