#pragma once
#include <windows.h>

HANDLE open_to_check(DWORD pid);
HANDLE open_to_check_read(DWORD pid);
HANDLE open_to_write_operation(DWORD pid);