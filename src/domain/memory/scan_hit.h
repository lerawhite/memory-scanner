#pragma once
#include "domain\memory\memory_region.h"
#include <iostream>


struct scan_hit
{
	BYTE* adr;
	std::string scan_string;
	memory_region region;
	SIZE_T count_of_find_strings;

};