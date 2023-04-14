#pragma once
#ifdef _DEBUG

#include <gmock/gmock-function-mocker.h>

#include "IOperatingSystem.h"


class MockWindowsAPIWrapper : public IOperatingSystem
{
public:
    MOCK_METHOD(bool, GetMessageWrapper, (EventMessage* MessageQueueMessage), (override));
};

#endif