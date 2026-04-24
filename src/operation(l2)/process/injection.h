#pragma once


#include <iostream>
#include <windows.h>

#include "core(l1)\utils\unique_handle.h"
#include "core(l1)\security\open_process_with_rights.h"

void* inject_string(DWORD pid, const std::string& string);

void* inject_string_in_special_addr(DWORD pid, void* spec_addr, const std::string& string);