#include "app(l4)\scenario\process_inspector_n_memory_scanner.h"


bool process_inspector_n_memory_scanner()
{

	entry_screen();


	load_processes();


	filter_process_by_name();


	see_token_rights_of_process();


	inject_string_in_process();


	memory_scanner();

	return 0;

}
