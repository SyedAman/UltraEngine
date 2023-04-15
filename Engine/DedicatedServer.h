#pragma once

class ISocket;

class DedicatedServer
{
public:
    DedicatedServer(ISocket* socket) {}
    bool CreateSocket();
};
