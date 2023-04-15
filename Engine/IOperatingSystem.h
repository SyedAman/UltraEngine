#pragma once


struct EventMessage
{
    unsigned int message;
};

class IOperatingSystem
{
public:
    // TODO: Add a destructor with unit tests.
    virtual bool GetEventMessage(EventMessage* MessageQueueMessage) = 0;
};
