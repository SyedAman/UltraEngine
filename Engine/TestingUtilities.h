#pragma once
#ifdef _DEBUG

#include <gmock/gmock-function-mocker.h>

#include "IWindowsAPI.h"


class MockWindowsAPIWrapper : public IWindowsAPI
{
public:
    MOCK_METHOD(bool, GetMessage, (LPMSG LoopMessage), (override));
};

#endif