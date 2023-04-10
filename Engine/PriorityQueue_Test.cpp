#include "PriorityQueue.h"

#include <gtest/gtest.h>

#include "Pair.h"

TEST(PriorityQueue, ShouldReturnTrueOnCallingEmptyWhenEmpty)
{
    PriorityQueue<int> Queue;
    EXPECT_TRUE(Queue.Empty());
}

TEST(PriorityQueue, ShouldPushOneElement)
{
    PriorityQueue<int> Queue;
    Queue.Push(1);
    EXPECT_FALSE(Queue.Empty());
}

TEST(PriorityQueue, ShouldPopOneElement)
{
    PriorityQueue<int> Queue;
    Queue.Push(1);
    Queue.Pop();
    EXPECT_TRUE(Queue.Empty());
}

TEST(PriorityQueue, ShouldTopOneElement)
{
    PriorityQueue<int> Queue;
    Queue.Push(1);
    EXPECT_EQ(1, Queue.Top());
}

TEST(PriorityQueue, ShouldSupportTemplates)
{
    PriorityQueue<int> IntQueue;
    PriorityQueue<float> FloatQueue;
    PriorityQueue<std::string> StringQueue;
    PriorityQueue<std::vector<int>> VectorQueue;
    PriorityQueue<Pair<int, int>> PairQueue;

    IntQueue.Push(1);
    FloatQueue.Push(1.0f);
    StringQueue.Push("1");
    VectorQueue.Push({1});
    PairQueue.Push({1, 1});
}

TEST(PriorityQueue, ShouldTopAndPopInOrder)
{
    PriorityQueue<int> Queue;
    Queue.Push(1);
    Queue.Push(2);
    Queue.Push(3);
    Queue.Push(0);
    Queue.Push(7);
    Queue.Push(-1);
    Queue.Push(4);

    EXPECT_EQ(-1, Queue.Top());
    Queue.Pop();
    EXPECT_EQ(0, Queue.Top());
    Queue.Pop();
    EXPECT_EQ(1, Queue.Top());
    Queue.Pop();
    EXPECT_EQ(2, Queue.Top());
    Queue.Pop();
    EXPECT_EQ(3, Queue.Top());
    Queue.Pop();
    EXPECT_EQ(4, Queue.Top());
    Queue.Pop();
    EXPECT_EQ(7, Queue.Top());
    Queue.Pop();
    EXPECT_TRUE(Queue.Empty());
}

TEST(PriorityQueue, ShouldNotDoublePop)
{
    PriorityQueue<int> Queue;
    Queue.Pop();
    Queue.Push(100);
    EXPECT_EQ(Queue.Top(), 100);
    Queue.Pop();
    Queue.Pop();
    EXPECT_EQ(Queue.Empty(), true);
}

TEST(PriorityQueue, ShouldThrowErrorOnTopWhenEmpty)
{
    try {
        PriorityQueue<int> Queue;
        Queue.Top();
        FAIL();
    }
    catch (std::runtime_error& e) {
        EXPECT_STREQ(e.what(), "PriorityQueue is empty");
    }
}