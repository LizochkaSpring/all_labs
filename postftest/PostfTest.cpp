#include "MyPostf.h"
#include <gtest.h>
TEST(MyPostfix, can_create_postfix)
{
	ASSERT_NO_THROW(MyPostfix p());
}

TEST(MyPostfix, can_get_infix)
{
	MyPostfix p("a+b-c");
	EXPECT_EQ(p.GetInfix(), "a+b-c");
}

TEST(MyPostfix, can_get_postfix)
{
	MyPostfix p("a+b-c");

	vector<string> expected = { "a", "b", "+", "c", "-" };
	EXPECT_EQ(p.GetPostfix(), expected);
}

TEST(MyPostfix, can_get_operands)
{
	MyPostfix p("a+b-c");
	vector<string> op;
	op.push_back("a");
	op.push_back("b");
	op.push_back("c");
	EXPECT_EQ(p.GetOperands(), op);
}

TEST(MyPostfix, can_get_postfix_with_parentheses)
{
	MyPostfix p("a+(b-c)");
	vector<string> expected = { "a", "b", "c", "-", "+" };
	EXPECT_EQ(expected, p.GetPostfix());
}

TEST(MyPostfix, can_get_postfix_with_double_parentheses)
{
	MyPostfix p("a*((b+c)-d)/e");
	vector<string> expected = { "a", "b", "c", "+", "d", "-", "*", "e", "/" };
	EXPECT_EQ(expected, p.GetPostfix());
}

TEST(MyPostfix, can_calculate_correct_positive_value_literal_expression)
{
	MyPostfix p("a+b-c*d");
	map<string, double> values = { {"a", 5}, {"b", 4}, {"c", 3}, {"d", 2} };
	ASSERT_EQ(3, p.Calculate(values));
}

TEST(MyPostfix, can_calculate_correct_negative_value_literal_expression)
{
	MyPostfix p("a+b-c*d");
	map<string, double> values = { {"a", 1}, {"b", 3}, {"c", 6}, {"d", 2} };
	ASSERT_EQ(-8, p.Calculate(values));
}

TEST(MyPostfix, can_calculate_correct_positive_value_numeric_expression)
{
	MyPostfix p("5+4-3*2");
	map<string, double> values = { {"5", 5}, {"4", 4}, {"3", 3}, {"2", 2} };
	ASSERT_EQ(3, p.Calculate(values));
}

TEST(MyPostfix, can_calculate_correct_negative_value_numeric_expression)
{
	MyPostfix p("1+3-6*2");
	map<string, double> values = { {"1", 1}, {"3", 3}, {"6", 6}, {"2", 2} };
	ASSERT_EQ(-8, p.Calculate(values));
}

TEST(MyPostfix, can_calculate_correct_positive_value_literal_and_numeric_expression)
{
	MyPostfix p("a+b-3*d");
	map<string, double> values = { {"a", 5}, {"b", 4}, {"3", 3}, {"d", 2} };
	ASSERT_EQ(3, p.Calculate(values));
}

TEST(MyPostfix, can_calculate_correct_negative_value_literal_and_numeric_expression)
{
	MyPostfix p("1+b-6*d");
	map<string, double> values = { {"1", 1}, {"b", 3}, {"6", 6}, {"d", 2} };
	ASSERT_EQ(-8, p.Calculate(values));
}