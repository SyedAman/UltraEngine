// Copyright Syed Aman. All Rights Reserved.
#pragma once

class ISocket;

class Server
{
public:
    Server(ISocket* socket) {}
    bool CreateSocket();
};
