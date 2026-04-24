
#include "operation(l2)\process\injection.h"

void* inject_string(DWORD pid, const std::string& string)
{

	const void* pattern = reinterpret_cast<const void*>(string.data());
	SIZE_T string_size = string.size();

	uniquehandle handle(open_to_write_operation(pid));

	if (handle.get() == nullptr)
	{
		std::cout << "open_process error\n\n" << GetLastError(); //adel
		return nullptr;
	}

	void* addr = VirtualAllocEx(handle.get(), NULL, string_size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

	if (addr == nullptr)
	{
		std::cout << "virtual_alloc error\n\n" << GetLastError();
		return nullptr;
	}
		

	if (!WriteProcessMemory(handle.get(), addr, pattern, string_size, NULL))
	{
		std::cout << "write_process_error\n\n" << GetLastError();
		return nullptr;
	}

	return addr;
}



void* inject_string_in_special_addr(DWORD pid, void* spec_addr, const std::string& string )
{

	const void* pattern = reinterpret_cast<const void*>(string.data());
	SIZE_T string_size = string.size();

	uniquehandle handle(open_to_write_operation(pid));

	if (handle.get() == nullptr)
	{
		std::cout << "open_process error\n\n" << GetLastError();
		return nullptr;
	}

	void* addr = VirtualAllocEx(handle.get(), spec_addr, string_size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

	if (addr == nullptr)
	{
		std::cout << "virtual_alloc error\n\n" << GetLastError();

		if (!WriteProcessMemory(handle.get(), spec_addr, pattern, string_size, NULL))
		{
			std::cout << "write_process_error\n\n" << GetLastError();
			return nullptr;
		}
		return spec_addr;
	}

	else
	{
		if (!WriteProcessMemory(handle.get(), addr, pattern, string_size, NULL))
		{
			std::cout << "write_process_error\n\n" << GetLastError();
			return nullptr;
		}
		return addr;
	}

	
}