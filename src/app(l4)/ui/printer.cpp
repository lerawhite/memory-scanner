
#include "app(l4)\ui\printer.h"

void printer(const processinfo& p)
{
	std::wcout << "name: " << p.name << std::endl;
	std::cout << "pid: " << p.pid << std::endl;
	std::cout << "ppid: " << p.ppid << std::endl;
	std::cout << "count_of_threads: " << p.cthread << std::endl << std::endl;
}

void printer(const token_info& t)
{
	std::cout << "pid: " << t.pid << std::endl;
	std::cout << "SID: " << t.SID << std::endl;
	std::cout << "IL: " << t.IL << std::endl << std::endl;
}