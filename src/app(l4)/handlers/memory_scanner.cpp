
#include "app(l4)\handlers\memory_scanner.h"

bool memory_scanner()
{

	std::cout << "press 'Y' to  to scan memory of process or 'C' to continue\n\n" << std::endl;

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

		DWORD pid;
		std::cout << "if you want to scan memory of process write a pid\n\n" << std::endl;
		std::cin >> pid;
		std::string pattern;
		std::cout << "if you want to scan memory of process write a pattern\n\n" << std::endl;
		std::cin >> pattern;



		auto result = scan_process_memory(pid, pattern);

		if (!result.size())
			std::cout << std::endl << "no information after scanning\n\n";


		for (auto &data : result)
		{
			std::cout << std::endl << data.scan_string << std::endl;
			std::cout << std::endl << (void*)data.adr << std::endl;
			//std::cout << std::endl << (void*)data.region.type << std::endl;
			//std::cout << std::endl << (void*)data.region.protect << std::endl;
		}
		
		std::cout << std::endl <<"count of finding strings: " << result.size() << std::endl;

		char decide;
		std::cout << "if you want to rescan memory processe press 'R' and 'C' to continue..\n\n" << std::endl;
		std::cin >> decide;

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



