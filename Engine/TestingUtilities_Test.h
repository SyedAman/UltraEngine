// Copyright Syed Aman. All Rights Reserved.
#pragma once
#ifdef _DEBUG

#include <gmock/gmock-function-mocker.h>

#include "IOperatingSystem.h"


class MockWindowsAPIWrapper : public IOperatingSystem
{
public:
    MOCK_METHOD(bool, GetEventMessage, (EventMessage* MessageQueueMessage), (override));
};

#endif