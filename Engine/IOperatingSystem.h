#pragma once


struct EventMessage
{
    unsigned int message;
};

class IOperatingSystem
{
public:
    virtual ~IOperatingSystem() = default;
    virtual bool GetEventMessage(EventMessage* MessageQueueMessage) = 0;
};
