#pragma once
#include "ISocket.h"

class WinSocket : public ISocket
{
public:
    static const int INVALID_SOCKET_DESCRIPTOR = -1;
    
    int GetSocketDescriptor();
    bool Create() override;
};
