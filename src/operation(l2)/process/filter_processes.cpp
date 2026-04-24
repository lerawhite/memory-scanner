
#include "operation(l2)\process\filter_processes.h"

std::vector<processinfo> filter_by_name(const std::vector<processinfo>& all_proc, const std::wstring& name)
{

	std::vector<processinfo> result;

	for (const auto& p : all_proc)
	{
		if (p.name == name)
		{
			result.push_back(p);
		}
	}
	return result;
}


bool exist_by_name(const std::vector<processinfo>& all_proc, const std::wstring& name)
{
	int i = 0;

	for (const auto& p : all_proc)
	{
		if (p.name == name)
			i++;
	}

	if (i > 0)
		return true;
	return false;

}