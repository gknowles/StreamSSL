#pragma once

#pragma warning(                                                            \
   disable : 4100 /* 'identifier': unreferenced formal parameter */         \
   4189 /* 'identifier': local variable is initialized but not refrenced */ \
   4238 /* nonstandard extension used: class rvalue used as lvalue */       \
   4456 /* declaration of 'identifier' hides previous local declaration */  \
   4457 /* declaration of 'identifier' hides function parameter */          \
   4458 /* declaration of 'identifier' hides class member */\
)

#ifndef WINVER
#define WINVER \
   _WIN32_WINNT_VISTA // Allow use of features specific to Windows 6 (Vista)
                      // or later
#endif

// Define a bool to check if this is a DEBUG or RELEASE build
#if defined(_DEBUG)
const bool debug = true;
#else
const bool debug = false;
#endif

#include <tchar.h>

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN // Exclude rarely-used stuff from Windows headers
#endif

#define Stringize(L) #L
#define MakeString(M, L) M(L)
#define $Line MakeString(Stringize, __LINE__)
#define Reminder __FILE__ "(" $Line ") : Reminder: "
// usage #pragma message(Reminder "your message here")

#define WIN32_LEAN_AND_MEAN
#include <afxwin.h>

void SetThreadName(const char * threadName);
void SetThreadName(const char * threadName, DWORD dwThreadID);
void DebugMsg(const WCHAR * pszFormat, ...);
void DebugMsg(const CHAR * pszFormat, ...);
void PrintHexDump(
   DWORD length,
   const void * const buf,
   const bool verbose = true);
bool IsUserAdmin();
