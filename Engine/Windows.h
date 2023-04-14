#pragma once
#include "IOperatingSystem.h"
#include <Windows.h>

class Windows : public IOperatingSystem
{
public:
    // TODO: Unit test if it is an actual singleton?
    static Windows& Instance();

    bool GetMessageWrapper(EventMessage* LoopMessage) override;

    typedef BOOL(WINAPI *GetMessageFuncPtr)(LPMSG, HWND, UINT, UINT);
    GetMessageFuncPtr GetMessagePtr = ::GetMessage;
};
