#include "DedicatedServer.h"

#include <gmock/gmock-function-mocker.h>
#include <gmock/gmock-spec-builders.h>
#include <gtest/gtest.h>

#include "ISocket.h"


class MockSocket : public ISocket
{
public:
    MOCK_METHOD(bool, Create, (), (override));
    MOCK_METHOD(int, GetSocketDescriptor, (), (override));
};

TEST(DedicatedServer, ShouldInstantiateDedicatedServer)
{
    MockSocket mockSocket;
    DedicatedServer server(&mockSocket);
    EXPECT_NE(nullptr, &server);
}

TEST(DedicatedServer, ShouldCreateValidSocket)
{
    MockSocket mockSocket;
    DedicatedServer server(&mockSocket);
    
    ON_CALL(mockSocket, Create())
        .WillByDefault(testing::Return(true));
    ON_CALL(mockSocket, GetSocketDescriptor())
        .WillByDefault(testing::Return(100));
    
    ASSERT_TRUE(server.CreateSocket());
    const int socketDescriptor = mockSocket.GetSocketDescriptor();
    ASSERT_NE(socketDescriptor, mockSocket.INVALID_SOCKET_DESCRIPTOR);
}