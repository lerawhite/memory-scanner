#pragma once
#include <vector>
#include "domain\process\process_info.h"

std::vector<processinfo> filter_by_name(const std::vector<processinfo>& all_proc, const std::wstring& name);

bool exist_by_name(const std::vector<processinfo>& all_proc, const std::wstring& name);