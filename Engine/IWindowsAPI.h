#pragma once
#include <Windows.h>

class IWindowsAPI
{
public:
    virtual BOOL GetMessage(LPMSG LoopMessage) = 0;
};
