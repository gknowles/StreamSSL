#pragma once

// handy functions declared in this file
HRESULT ShowCertInfo(PCCERT_CONTEXT pCertContext, CString Title);
HRESULT CertTrusted(PCCERT_CONTEXT pCertContext);
bool MatchCertHostName(PCCERT_CONTEXT pCertContext, LPCWSTR hostname);
SECURITY_STATUS CertFindClient(
   PCCERT_CONTEXT & pCertContext,
   const LPCTSTR pszSubjectName = NULL);
SECURITY_STATUS CertFindFromIssuerList(
   PCCERT_CONTEXT & pCertContext,
   SecPkgContext_IssuerListInfoEx & IssuerListInfo);
CString GetHostName(COMPUTER_NAME_FORMAT WhichName = ComputerNameDnsHostname);
CString GetUserName(void);
