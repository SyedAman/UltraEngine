// Copyright Syed Aman. All Rights Reserved.
#include "WindowsOS.h"

WindowsOS& WindowsOS::Instance()
{
    static WindowsOS Instance;
    return Instance;
}

bool WindowsOS::GetEventMessage(EventMessage* LoopMessage)
{
    MSG msg;
    const bool result = GetMessagePtr(&msg, NULL, 0, 0);
    LoopMessage->message = msg.message;
    return result;
}
