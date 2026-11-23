
#pragma once

/* PSDK/NDK Headers */
#define WIN32_NO_STATUS
#include <windef.h>
#include <winbase.h>

/* Redefine NTDDI_VERSION to 2K3 SP1 to get correct NDK definitions */
#undef NTDDI_VERSION
#define NTDDI_VERSION NTDDI_WS03SP1

#define NTOS_MODE_USER
#include <ndk/iofuncs.h>
#include <ndk/kefuncs.h>
#include <ndk/obfuncs.h>
#include <ndk/psfuncs.h>
#include <ndk/rtlfuncs.h>

/* CSRSS Headers */
#include <win/base.h>

/* Internal Kernel32 Header */
#include "../include/kernel32.h"

/* Module handle of kernel32.dll, set at DLL_PROCESS_ATTACH (kernel32: client/dllmain.c;
   kernel32_vista: DllMain.c). Code shared by both DLLs uses it instead of
   GetModuleHandleW, which takes the loader lock (LdrGetDllHandleEx): callers such
   as the UCRT call these functions while holding their own locks, which a new
   thread acquires under the loader lock (DLL_THREAD_ATTACH). That lock order
   inversion deadlocks. */
extern HMODULE kernel32_handle;
