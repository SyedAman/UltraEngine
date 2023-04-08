#include "PriorityQueue.h"

#include <gtest/gtest.h>

#include "Pair.h"

TEST(PriorityQueue, ShouldReturnTrueOnCallingEmptyWhenEmpty)
{
    PriorityQueue<int> Queue;
    EXPECT_TRUE(Queue.empty());
}

TEST(PriorityQueue, ShouldPushOneElement)
{
    PriorityQueue<int> Queue;
    Queue.push(1);
    EXPECT_FALSE(Queue.empty());
}

TEST(PriorityQueue, ShouldPopOneElement)
{
    PriorityQueue<int> Queue;
    Queue.push(1);
    Queue.pop();
    EXPECT_TRUE(Queue.empty());
}

TEST(PriorityQueue, ShouldTopOneElement)
{
    PriorityQueue<int> Queue;
    Queue.push(1);
    EXPECT_EQ(1, Queue.top());
}

TEST(PriorityQueue, ShouldSupportTemplates)
{
    PriorityQueue<int> IntQueue;
    PriorityQueue<float> FloatQueue;
    PriorityQueue<std::string> StringQueue;
    PriorityQueue<std::vector<int>> VectorQueue;
    PriorityQueue<Pair<int, int>> PairQueue;

    IntQueue.push(1);
    FloatQueue.push(1.0f);
    StringQueue.push("1");
    VectorQueue.push({1});
    PairQueue.push({1, 1});
}

TEST(PriorityQueue, ShouldTopAndPopInOrder)
{
    PriorityQueue<int> Queue;
    Queue.push(1);
    Queue.push(2);
    Queue.push(3);
    Queue.push(0);
    Queue.push(7);
    Queue.push(-1);
    Queue.push(4);

    EXPECT_EQ(-1, Queue.top());
    Queue.pop();
    EXPECT_EQ(0, Queue.top());
    Queue.pop();
    EXPECT_EQ(1, Queue.top());
    Queue.pop();
    EXPECT_EQ(2, Queue.top());
    Queue.pop();
    EXPECT_EQ(3, Queue.top());
    Queue.pop();
    EXPECT_EQ(4, Queue.top());
    Queue.pop();
    EXPECT_EQ(7, Queue.top());
    Queue.pop();
    EXPECT_TRUE(Queue.empty());
}

TEST(PriorityQueue, ShouldNotDoublePop)
{
    PriorityQueue<int> Queue;
    Queue.pop();
    Queue.push(100);
    EXPECT_EQ(Queue.top(), 100);
    Queue.pop();
    Queue.pop();
    EXPECT_EQ(Queue.empty(), true);
}

TEST(PriorityQueue, ShouldThrowErrorOnTopWhenEmpty)
{
    try {
        PriorityQueue<int> Queue;
        Queue.top();
        FAIL();
    }
    catch (std::runtime_error& e) {
        EXPECT_STREQ(e.what(), "PriorityQueue is empty");
    }
}