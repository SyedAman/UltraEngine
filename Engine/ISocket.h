﻿#pragma once

class ISocket
{
public:
    static const int INVALID_SOCKET_DESCRIPTOR = -1;

    virtual bool Create() = 0;
    virtual int GetSocketDescriptor() = 0;
};
