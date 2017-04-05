#pragma once

#include "Utilities/Utilities.h"

// Windows SDK
#include <cryptuiapi.h>
#include <WS2tcpip.h>
#include <MSTcpIP.h>
#include <wincrypt.h>
#include <WinDNS.h>
#include <wintrust.h>
#include <schannel.h>
#define SECURITY_WIN32
#include <security.h>

// Standard C++
#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <memory>
#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Application
#include "ActiveSock.h"
#include "EventWrapper.h"
#include "Handle.h"
#include "ISocketStream.h"
#include "SecurityHandle.h"
#include "SSLClient.h"
#include "SSLHelper.h"

#pragma comment(lib, "crypt32.lib")
#pragma comment(lib, "cryptui.lib")
#pragma comment(lib, "Dnsapi.lib")
#pragma comment(lib, "secur32.lib")
#pragma comment(lib, "Ws2_32.lib")
