
#include "app(l4)\handlers\injection_in_process.h"


bool inject_string_in_process()
{

	std::cout << "press 'Y' if you like to inject string in process or any other variant if wouldnt \n\n" << std::endl;

	char decide_;
	std::cin >> decide_;

	while (true)
	{

		if (decide_ == 'Y')
			break;
		else
			break;
	}

	while (true)
	{
		if (decide_ != 'Y')
		{
			break;
		}
			


		char decide;

		std::cout << std::endl << "press 'Y' if you like to inject in special address or any other variant if wouldnt \n\n";
		std::cin >> decide;

		if (decide == 'Y')
		{
			DWORD pid;
			std::cout << std::endl << "vvedite pid to inject\n\n";
			std::cin >> pid;

			std::string string;
			std::cout << std::endl << "vvedite stroky to inject\n\n";
			std::cin >> string;

			uintptr_t addr_int;
			std::cout << std::endl << "vvedite address to inject\n\n";
			std::cin >> std::hex >> addr_int;

			void* spec_addr = reinterpret_cast<void*>(addr_int);

			if (inject_string_in_special_addr(pid, spec_addr, string) == nullptr)
				std::cout << std::endl << "error with injection\n\n";
			else
				std::cout << std::endl << "injection is success in \n\n" << addr_int << std::endl;
		}


		else
		{
			DWORD pid;
			std::cout << std::endl << "vvedite pid to inject\n\n";
			std::cin >> pid;

			std::string string;
			std::cout << std::endl << "vvedite stroky to inject\n\n";
			std::cin >> string;

			void* address_of_inject;
			address_of_inject = inject_string(pid, string);
			if (address_of_inject == nullptr)
				std::cout << std::endl << "error with injection\n\n";
			else
				std::cout << std::endl << "injection is success in "<< "0x" << address_of_inject <<std::endl;
		}

	
		std::cout << "if you want to inject one more string press 'R' or 'C' to continue..\n\n" << std::endl;


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

