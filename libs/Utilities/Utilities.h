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
#include <schannel.h>
#include <wincrypt.h>

#pragma comment(lib, "crypt32.lib")


//===========================================================================
// General utilities
void SetThreadName(const char * threadName);
void SetThreadName(const char * threadName, DWORD dwThreadID);
void DebugMsg(const WCHAR * pszFormat, ...);
void DebugMsg(const CHAR * pszFormat, ...);
void PrintHexDump(
   DWORD length,
   const void * const buf,
   const bool verbose = true);
bool IsUserAdmin();


//===========================================================================
// SSL Utilities
HRESULT ShowCertInfo(PCCERT_CONTEXT pCertContext, CString Title);
bool MatchCertHostName(PCCERT_CONTEXT pCertContext, LPCWSTR hostname);
CString GetHostName(COMPUTER_NAME_FORMAT WhichName = ComputerNameDnsHostname);
CString GetUserName(void);

HRESULT CertTrustedServer(PCCERT_CONTEXT pCertContext);
SECURITY_STATUS CertFindServerByName(
   PCCERT_CONTEXT & pCertContext,
   LPCTSTR pszSubjectName,
   boolean fUserStore = false);

HRESULT CertTrustedClient(PCCERT_CONTEXT pCertContext);
SECURITY_STATUS CertFindClient(
   PCCERT_CONTEXT & pCertContext,
   const LPCTSTR pszSubjectName = NULL);
SECURITY_STATUS CertFindFromIssuerList(
   PCCERT_CONTEXT & pCertContext,
   SecPkgContext_IssuerListInfoEx & IssuerListInfo);

class CSSLHelper {
private:
   const byte * const OriginalBufPtr;
   const byte * DataPtr; // Points to data inside message
   const byte * BufEnd;
   const int MaxBufBytes;
   UINT8 contentType, major, minor;
   UINT16 length;
   UINT8 handshakeType;
   UINT16 handshakeLength;
   bool CanDecode();
   bool decoded;

public:
   CSSLHelper(const byte * BufPtr, const int BufBytes);
   ~CSSLHelper();
   // Max length of handshake data buffer
   void TraceHandshake();
   // Is this packet a complete client initialize packet
   bool IsClientInitialize();
   // Get SNI provided hostname
   CString GetSNI();
};
