
#include "k32_vista.h"

/* kernel32.dll module handle, used by the shared kernel32_vista code */
HMODULE kernel32_handle = NULL;

BOOL
WINAPI
DllMain(HANDLE hDll,
        DWORD dwReason,
        LPVOID lpReserved)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        /* Cache the kernel32 module handle for the shared code (see
           EnumSystemLocalesEx.c). The loader lock is already held here. */
        kernel32_handle = GetModuleHandleW(L"kernel32.dll");
        DisableThreadLibraryCalls(hDll);
    }
    return TRUE;
}
