#include "core(l1)/utils/unique_handle.h"



uniquehandle::uniquehandle(HANDLE h) : handle(h) {}

uniquehandle::~uniquehandle()
{
	if (handle && handle != INVALID_HANDLE_VALUE)
		CloseHandle(handle);
}

HANDLE uniquehandle::get() const
{
	return handle;
}