#pragma once
#include "IWindowsAPI.h"
#include <Windows.h>

class WindowsAPIWrapper : public IWindowsAPI
{
public:
    // TODO: Unit test if it is an actual singleton?
    static WindowsAPIWrapper& Instance();

    bool GetMessageWrapper(EventMessage* LoopMessage) override;

    typedef BOOL(WINAPI *GetMessageFuncPtr)(LPMSG, HWND, UINT, UINT);
    GetMessageFuncPtr GetMessagePtr = ::GetMessage;
};
