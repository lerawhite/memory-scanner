
#include "core(l1)\memory\read_process_memory.h"

bool read_memory(HANDLE handle, void* addr, void* buffer, SIZE_T t, SIZE_T& out_read)
{
	if (!ReadProcessMemory(handle, addr, buffer, t, &out_read))
		return false;
	return out_read > 0;
}