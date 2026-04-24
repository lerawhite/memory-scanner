#pragma once
#include <windows.h>

bool read_memory(HANDLE handle, void* addr, void* buffer, SIZE_T t, SIZE_T& out_read);