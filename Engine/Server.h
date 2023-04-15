#pragma once

class ISocket;

class Server
{
public:
    Server(ISocket* socket) {}
    bool CreateSocket();
};
