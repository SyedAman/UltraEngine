#include "PriorityQueue.h"

#include <gtest/gtest.h>

TEST(PriorityQueueTest, ShouldReturnTrueOnCallingEmptyWhenEmpty)
{
    PriorityQueue<int> Queue;
    EXPECT_TRUE(Queue.empty());
}

TEST(PriorityQueueTest, ShouldPushOneElement)
{
    PriorityQueue<int> Queue;
    Queue.push(1);
    EXPECT_FALSE(Queue.empty());
}

TEST(PriorityQueueTest, PopOneElement)
{
    PriorityQueue<int> Queue;
    Queue.push(1);
    Queue.pop();
    EXPECT_TRUE(Queue.empty());
}

TEST(PriorityQueueTest, TopOneElement)
{
    PriorityQueue<int> Queue;
    Queue.push(1);
    EXPECT_EQ(1, Queue.top());
}

TEST(PriorityQueueTest, Templates)
{
    PriorityQueue<int> IntQueue;
    PriorityQueue<float> FloatQueue;
    PriorityQueue<std::string> StringQueue;
    PriorityQueue<std::vector<int>> VectorQueue;
    PriorityQueue<std::pair<int, int>> PairQueue;

    IntQueue.push(1);
    FloatQueue.push(1.0f);
    StringQueue.push("1");
    VectorQueue.push({1});
    PairQueue.push({1, 1});
}