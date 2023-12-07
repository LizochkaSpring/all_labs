#include "Queue.h"
#include <gtest.h>
TEST(Queue, can_create_queue)
{
	ASSERT_NO_THROW(Queue<int> q(5));
}

TEST(Queue, cant_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(Queue<int> q(-4));
}

TEST(Queue, can_check_queue_is_empty)
{
	Queue<int> q(5);
	EXPECT_TRUE(q.IsEmpty());
}

TEST(Queue, can_get_size)
{
	Queue<int> q(5);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	EXPECT_EQ(q.GetSize(), 3);
}

TEST(Queue, can_put_elem)
{
	Queue<int> q(5);
	ASSERT_NO_THROW(q.Push(2));
}

TEST(Queue, can_check_first_element_withuot_remove)
{
	Queue<int> q(5);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	EXPECT_EQ(q.GetFirst(), 2);
}
