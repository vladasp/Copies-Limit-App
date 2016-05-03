#pragma once
#include "stdafx.h";
#include <array>
#include <msclr\marshal_cppstd.h>
#include <string>;
#include <windows.h>;

#using <System.dll>
using namespace System;
using namespace System::Diagnostics;
using namespace System::ComponentModel;


class CheckingLimit
{
public:
    CheckingLimit();
    ~CheckingLimit();

    int CanLocalRun(int limit, string name);
    int CanNetLockalRun(int limit, string name, string IP);
};

