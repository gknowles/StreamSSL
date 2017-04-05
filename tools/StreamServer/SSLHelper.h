#pragma once

// handy functions declared in this file
HRESULT ShowCertInfo(PCCERT_CONTEXT pCertContext, CString Title);
HRESULT CertTrusted(PCCERT_CONTEXT pCertContext);
SECURITY_STATUS CertFindServerByName(
   PCCERT_CONTEXT & pCertContext,
   LPCTSTR pszSubjectName,
   boolean fUserStore = false);
CString GetHostName(COMPUTER_NAME_FORMAT WhichName = ComputerNameDnsHostname);
CString GetUserName(void);

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
