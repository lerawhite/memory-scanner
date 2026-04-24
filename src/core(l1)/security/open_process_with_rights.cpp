
#include <iostream>
#include "core(l1)\security\open_process_with_rights.h"

HANDLE open_to_check(DWORD pid)
{
	if (HANDLE result = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pid))
		return result;
        return nullptr;
}

HANDLE open_to_check_read(DWORD pid)
{
	if (HANDLE result = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid))
		return result;
	    return nullptr;
}

HANDLE open_to_write_operation(DWORD pid)
{
	if (HANDLE result = OpenProcess(PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, pid))
		return result;
	    return nullptr;
}