#include "MyStack.h"
#include <gtest.h>

TEST(MyStack, can_create_stack_with_posit__ve_size) //����� ��������� ���� � ������������� ��������
{
	ASSERT_NO_THROW(MyStack<int> m);
}
TEST(MyStack, throws_when_create_stack_with_negative_length) //����������� ��� �������� ����� � ������������� ������
{
	ASSERT_ANY_THROW(MyStack<int> st(-7));
}

TEST(MyStack, compare_equal_stack_of_equal_size) //�������� ������ ������ ����������� �������
{
	MyStack<int> st1(7), st2(7);
	st1.Push(1);
	st1.Push(2);
	st1.Push(3);
	st1.Push(4);
	st1.Push(5);
	st1.Push(6);
	st1.Push(7);
	st2 = st1;

	EXPECT_EQ(st1, st2);
}

TEST(MyStack, compare_not_equal_stack_of_equal_size) //�������� �� ������ ������ ����������� �������
{
	MyStack<int> st1(7), st2(7);
	st1.Push(1);
	st1.Push(2);
	st1.Push(3);
	st1.Push(4);
	st1.Push(5);
	st1.Push(6);
	st1.Push(7);
	st2.Push(1);
	st2.Push(2);
	st2.Push(5);
	st2.Push(7);
	st2.Push(9);
	st2.Push(11);
	st2.Push(13);

	EXPECT_NE(st1, st2);
}

TEST(MyStack, check_empty_stack) //��������� ������ ������
{
	MyStack<int> st(7);

	EXPECT_EQ(1, st.isEmpty());
}

TEST(MyStack, check_not_empty_stack) //��������� �� ������ ������
{
	MyStack<int> st(7);
	st.Push(1);

	EXPECT_EQ(0, st.isEmpty());
}

TEST(MyStack, check_full_stack) //��������� ������ ����
{
	MyStack<int> st(7);
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);
	st.Push(5);
	st.Push(6);
	st.Push(7);

	EXPECT_EQ(1, st.isFull());
}

TEST(MyStack, check_not_full_stack) //��������� �� ������ ����
{
	MyStack<int> st(7);
	st.Push(1);

	EXPECT_EQ(0, st.isFull());
}

TEST(MyStack, can_set_elem_in_not_full_stack) //����� ���������� elem � �������� ����
{
	MyStack<int> st(7);
	st.Push(1);

	ASSERT_NO_THROW(st.Push(2));
}

TEST(MyStack, throws_when_set_elem_in_full_stack) //����������� ��� ������ �������� � ������ ����
{
	MyStack<int> st(7);
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);
	st.Push(5);
	st.Push(6);
	st.Push(7);

	ASSERT_ANY_THROW(st.Push(8));
}

TEST(MyStack, can_get_elem_in_not_empty_stack) //����� �������� ������� � �������� �����
{
	MyStack<int> st(7);
	st.Push(1);

	ASSERT_NO_THROW(st.Pop());
}

TEST(MyStack, throws_when_get_elem_in_empty_stack) //�����������, ����� �������� ������� � ������ ����
{
	MyStack<int> st(7);

	ASSERT_ANY_THROW(st.Pop());
}