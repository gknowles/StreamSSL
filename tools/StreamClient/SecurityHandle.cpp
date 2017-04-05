#include "pch.h"
#pragma hdrstop

void CredentialHandle::Close() noexcept {
   if (*this) {
      CSSLClient::g_pSSPI->FreeCredentialsHandle(&m_value);
   }
}

void SecurityContextHandle::Close() noexcept {
   if (*this) {
      CSSLClient::g_pSSPI->DeleteSecurityContext(&m_value);
   }
}
