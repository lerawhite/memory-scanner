
#include "operation(l2)\memory\query_memory_reg.h"

std::optional<memory_region> query_memory_reg(HANDLE handle, void* addr)
{
 
    MEMORY_BASIC_INFORMATION mbi{};


    if (!VirtualQueryEx(handle, addr, &mbi, sizeof(MEMORY_BASIC_INFORMATION)))
        return std::nullopt;

    memory_region reg;
    reg.adr = mbi.BaseAddress;
    reg.reg_size = mbi.RegionSize;
    reg.state = mbi.State;
    reg.protect = mbi.Protect;
    reg.type = mbi.Type;

    return reg;
}