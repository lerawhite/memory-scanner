
#include "app(l4)\handlers\load_processes.h"

bool load_processes()
{
	std::cout << "press 'Y' to load all processes or 'C' to continue\n\n" << std::endl;

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

		auto all_process = list_processes();

		for (const auto& p : all_process)
			printer(p);

		std::cout << std::endl << "total quantity of process - " << all_process.size() << std::endl << std::endl;

		char decide;
		std::cout << "if you want to reload processe press 'R' and 'C' to continue..\n\n" << std::endl;

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