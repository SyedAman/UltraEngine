#pragma once
#include "IWindowsAPI.h"

class WindowsAPIWrapper : public IWindowsAPI
{
public:
    static WindowsAPIWrapper& Instance();

    BOOL GetMessage(LPMSG LoopMessage) override;
};
