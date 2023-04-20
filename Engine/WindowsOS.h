// Copyright Syed Aman. All Rights Reserved.
/**
 * Wrapper for Windows API. This is to prevent tight coupling with Windows API that breaks code after new updates.
 */

#pragma once
#include "IOperatingSystem.h"
#include <Windows.h>

class WindowsOS : public IOperatingSystem
{
public:
    // TODO: Unit test if it is an actual singleton?
    static WindowsOS& Instance();

    bool GetEventMessage(EventMessage* LoopMessage) override;

    typedef BOOL(WINAPI *GetMessageFuncPtr)(LPMSG, HWND, UINT, UINT);
    GetMessageFuncPtr GetMessagePtr = ::GetMessage;
};
