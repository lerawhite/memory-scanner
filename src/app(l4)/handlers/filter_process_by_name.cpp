
#include "app(l4)\handlers\filter_process_by_name.h"

bool filter_process_by_name()
{

	std::cout << "press 'Y' to filter processes by name or 'C' to continue\n\n" << std::endl;

	char decide_;

	while (true)
	{
		std::cin >> decide_;
		if (decide_ == 'Y')
			break;
		if (decide_ == 'C')
			break;
		else
			continue;
	}

	while (true)
	{
		if (decide_ == 'C')
			break;


		std::wcout << std::endl << "write 'name' of process do you want to see \n " << std::endl;

		std::wstring name;
		std::wcin >> name;

		if (!exist_by_name(list_processes(), name))
			std::cout << "proccess with this name dont exist..\n\n" << std::endl;



		auto process_with_spec_name = filter_by_name(list_processes(), name);


		for (const auto& p : process_with_spec_name)
			printer(p);

		std::wcout << std::endl << "count of process with this name is :" << process_with_spec_name.size() << std::endl << std::endl;

		char decide;
		std::cout << "if you want to refilter processes press 'R' and 'C' to continue..\n\n" << std::endl;
	

		while (true)
		{
			std::cin >> decide;
			if (decide == 'R')
				break;
			if (decide == 'C')
				break;
			else
				continue;
		}

		if (decide == 'C')
			break;
	}
	return 0;
}
