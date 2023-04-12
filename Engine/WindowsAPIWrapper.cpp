#include "WindowsAPIWrapper.h"

WindowsAPIWrapper& WindowsAPIWrapper::Instance()
{
    static WindowsAPIWrapper Instance;
    return Instance;
}

bool WindowsAPIWrapper::GetMessage(LPMSG LoopMessage)
{
    return ::GetMessage(LoopMessage, NULL, 0, 0);
}
