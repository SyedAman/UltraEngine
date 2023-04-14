#include "Windows.h"

Windows& Windows::Instance()
{
    static Windows Instance;
    return Instance;
}

bool Windows::GetMessageWrapper(EventMessage* LoopMessage)
{
    MSG msg;
    const bool result = GetMessagePtr(&msg, NULL, 0, 0);
    LoopMessage->message = msg.message;
    return result;
}
