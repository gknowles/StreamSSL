#pragma once

#include "Utilities/Utilities.h"

// Windows SDK
#define SECURITY_WIN32
#include <security.h>

// Standard C++
#include <functional>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>

// Application
#include "ActiveSock.h"
#include "EventWrapper.h"
#include "Handle.h"
#include "ISocketStream.h"
#include "SecurityHandle.h"
#include "SSLClient.h"

#pragma comment(lib, "secur32.lib")
