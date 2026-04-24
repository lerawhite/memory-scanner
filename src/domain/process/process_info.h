#pragma once
#include <string>
#include <windows.h>
#include <tlhelp32.h>
#include <iostream>

struct processinfo
{
	std::wstring name;
	uint32_t pid;
	uint32_t ppid;
	uint32_t cthread;
};