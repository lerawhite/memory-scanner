#include "operation(l2)\process\list_processes.h"


std::vector<processinfo> list_processes()
{

	std::vector<processinfo> result;

	uniquehandle snap(CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0));

	if (snap.get() == INVALID_HANDLE_VALUE)
		return result;


	PROCESSENTRY32W  pe;
	pe.dwSize = sizeof(PROCESSENTRY32W);


	if (!Process32FirstW(snap.get(), &pe))
		return result;
	do
	{
		result.push_back(convert(pe));
	} while (Process32NextW(snap.get(), &pe));

	return result;

}