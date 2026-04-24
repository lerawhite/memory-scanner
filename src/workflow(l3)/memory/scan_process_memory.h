#pragma once


#include "core(l1)\memory\read_process_memory.h"
#include "core(l1)\utils\unique_handle.h"
#include "core(l1)\security\open_process_with_rights.h"
#include "core(l1)\security\flags_for_scanning.h"

#include "operation(l2)\memory\search_byte_pattern.h"
#include "operation(l2)\memory\query_memory_reg.h"

#include "domain\memory\scan_hit.h"
#include "domain\memory\memory_region.h"

#include <windows.h>
#include <vector>
#include <iostream>
#include <string>




std::vector <scan_hit> scan_process_memory(DWORD pid, const std::string& scan_string);