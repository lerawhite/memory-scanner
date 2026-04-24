#pragma once

#include "domain\memory\memory_region.h"
#include <optional>

std::optional<memory_region> query_memory_reg(HANDLE handle, void* addr);

