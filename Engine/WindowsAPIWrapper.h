#pragma once
#include "IWindowsAPI.h"

class WindowsAPIWrapper : public IWindowsAPI
{
public:
    // TODO: Unit test if it is an actual singleton?
    static WindowsAPIWrapper& Instance();

    bool GetMessage(LPMSG LoopMessage) override;
};
