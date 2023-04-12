#include "WindowsAPIWrapper.h"

WindowsAPIWrapper& WindowsAPIWrapper::Instance()
{
    static WindowsAPIWrapper Instance;
    return Instance;
}

BOOL WindowsAPIWrapper::GetMessageA(LPMSG LoopMessage)
{
    return ::GetMessage(LoopMessage, NULL, 0, 0);
}
