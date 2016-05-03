#pragma once

#include "stdafx.h"
#include <array>
#include <msclr\marshal_cppstd.h>
#include <string>;
#include <windows.h>;
#using <System.dll>
using namespace System;
using namespace System::Diagnostics;
using namespace System::ComponentModel;

namespace ProcessLimit
{
    extern "C"  __declspec(dllexport) int CanLocalRun(int limit, std::string name);
    extern "C"  __declspec(dllexport) int CanNetLockalRun(int limit, std::string name, std::string IP);
}
