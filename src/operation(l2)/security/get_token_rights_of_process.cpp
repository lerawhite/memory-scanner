
#include "operation(l2)\security\get_token_rights_of_process.h"


token_info get_token_rights_of_process(DWORD pid)
{
	token_info t_info;
	uniquehandle hprocess(open_to_check(pid)); 
	
	if (hprocess.get() == nullptr)
	{
		t_info.result = false;
		return t_info;
	}
		
 uniquehandle htoken(open_process_token(hprocess.get()));

	t_info.pid = pid;
	t_info.SID = get_SID(htoken.get());
	t_info.IL = get_IL(htoken.get());
	t_info.result = true;
	return t_info;
}