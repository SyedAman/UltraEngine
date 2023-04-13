#include "WindowsAPIWrapper.h"

WindowsAPIWrapper& WindowsAPIWrapper::Instance()
{
    static WindowsAPIWrapper Instance;
    return Instance;
}

bool WindowsAPIWrapper::GetMessageWrapper(EventMessage* LoopMessage)
{
    MSG msg;
    const bool result = GetMessagePtr(&msg, NULL, 0, 0);
    LoopMessage->message = msg.message;
    return result;
}
