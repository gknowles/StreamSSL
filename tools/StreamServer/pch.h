#pragma once

#include "Utilities/Utilities.h"

// Windows SDK
#include <WS2tcpip.h>
#define SECURITY_WIN32
#include <security.h>
#include <strsafe.h>

// Microsoft ToolKits
#include <afxmt.h>

// Standard C++
#include <functional>
#include <iostream>
#include <memory>

// Application
#include "ISocketStream.h"
#include "Listener.h"
#include "PassiveSock.h"
#include "SSLServer.h"
#include "Transport.h"

#pragma comment(lib, "secur32.lib")
