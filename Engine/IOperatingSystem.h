#pragma once


struct EventMessage
{
    unsigned int message;
};

class IOperatingSystem
{
public:
    // TODO: Add a destructor with unit tests.
    virtual bool GetMessageWrapper(EventMessage* MessageQueueMessage) = 0;
};
