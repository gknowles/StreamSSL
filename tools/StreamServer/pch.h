#pragma once

#include "Utilities/Utilities.h"

// Windows SDK
#include <WS2tcpip.h>
#include <wincrypt.h>
#include <wintrust.h>
#define SECURITY_WIN32
#include <security.h>
#include <schannel.h>
#include <cryptuiapi.h>
#include <strsafe.h>

// Microsoft ToolKits
#include <afxmt.h>

// Standard C++
#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <process.h>

// Application
#include "ISocketStream.h"
#include "Listener.h"
#include "PassiveSock.h"
#include "SSLHelper.h"
#include "SSLServer.h"
#include "Transport.h"

#pragma comment(lib, "cryptui.lib")
#pragma comment(lib, "Dnsapi.lib")
#pragma comment(lib, "secur32.lib")
