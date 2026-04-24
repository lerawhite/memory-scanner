
#include "app(l4)\handlers\see_token_rights_of_process.h"

bool see_token_rights_of_process()
{
	std::cout << "press 'Y' to see token rights of some process or 'C' to continue\n\n" << std::endl;
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


		std::wcout << std::endl << "write 'pid' of process thats rights do you want to see \n " << std::endl;

		DWORD pid;
		std::wcin >> pid;


		auto t = get_token_rights_of_process(pid);

		if (!t.result)
			std::cout << std::endl << "token_rights_denied_or_pid_is_invalid \n\n";
		else
			printer(t);


		char decide;
		std::cout << "if you want to recheck processes press 'R' and 'C' to continue..\n\n" << std::endl;

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