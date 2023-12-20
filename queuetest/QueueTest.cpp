#include "Queue.h"
#include <gtest.h>
TEST(MyQueue, can_create_queue)
{
	ASSERT_NO_THROW(MyQueue<int> q(5));
}

TEST(MyQueue, cant_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(MyQueue<int> q(-4));
}

TEST(MyQueue, can_check_queue_is_empty)
{
	MyQueue<int> q(5);
	EXPECT_TRUE(q.IsEmpty());
}

TEST(MyQueue, can_get_size)
{
	MyQueue<int> q(5);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	EXPECT_EQ(q.GetSize(), 3);
}

TEST(MyQueue, can_put_elem)
{
	MyQueue<int> q(5);
	ASSERT_NO_THROW(q.Push(2));
}

TEST(MyQueue, can_check_first_element_withuot_remove)
{
	MyQueue<int> q(5);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	EXPECT_EQ(q.GetFirst(), 2);
}
