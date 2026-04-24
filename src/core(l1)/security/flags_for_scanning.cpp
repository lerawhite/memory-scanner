
#include "core(l1)\security\flags_for_scanning.h"


bool is_readable(DWORD protect)
{
    if (protect & PAGE_GUARD) return false;
    if (protect & PAGE_NOACCESS) return false;

    DWORD readable =
        PAGE_READONLY |
        PAGE_READWRITE |
        PAGE_WRITECOPY |
        PAGE_EXECUTE_READ |
        PAGE_EXECUTE_READWRITE |
        PAGE_EXECUTE_WRITECOPY;

    return (protect & readable) != 0;
}