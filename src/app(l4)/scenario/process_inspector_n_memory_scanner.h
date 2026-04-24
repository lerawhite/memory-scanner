#pragma once
#include <iostream>
#include "operation(l2)\process\list_processes.h"
#include "operation(l2)\process\filter_processes.h"
#include "operation(l2)\security\get_token_rights_of_process.h"

#include "app(l4)\handlers\entry_screen.h"
#include "app(l4)\handlers\load_processes.h"
#include "app(l4)\handlers\filter_process_by_name.h"
#include "app(l4)\handlers\see_token_rights_of_process.h"
#include "app(l4)\handlers\memory_scanner.h"
#include "app(l4)\handlers\injection_in_process.h"

bool process_inspector_n_memory_scanner();