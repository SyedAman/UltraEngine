#pragma once


struct EventMessage
{
    unsigned int message;
};

class IWindowsAPI
{
public:
    // TODO: Add a destructor with unit tests.
    virtual bool GetMessageWrapper(EventMessage* MessageQueueMessage) = 0;
};
