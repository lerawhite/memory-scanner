#pragma once
#include <windows.h>
#include <string>
#include <vector>
#include <sddl.h>
#include <iostream>
#include "core(l1)\security\open_process_with_rights.h"
#include "core(l1)\utils\unique_handle.h"



 HANDLE open_process_token(HANDLE process);

 std::string get_SID(HANDLE htoken);

 std::string get_IL(HANDLE htoken);

