#pragma once
#include <windows.h>
#include <sddl.h>
#include <iostream>
#include "core(l1)\security\open_process_with_rights.h"
#include "core(l1)\utils\unique_handle.h"
#include "core(l1)\security\get_token_rights.h"
#include "domain\security\token_info.h"



token_info get_token_rights_of_process(DWORD pid);