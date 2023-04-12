#pragma once
// TODO: Get rid of direct dependency on Windows.h (Dependency inversion principle).
#include <Windows.h>

class IWindowsAPI
{
public:
    // TODO: Add a destructor with unit tests.
    virtual bool GetMessage(LPMSG LoopMessage) = 0;
};
