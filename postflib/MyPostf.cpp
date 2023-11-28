#include <math.h>
#include <string>
#include <cstdlib>
#include "MyPostf.h"
#include <iostream>
#include "MyStack.h"
#include <stdexcept>

MyPostfix::MyPostfix(string infx) {
	if (infx.empty())
		throw "Stack is empty";
	infix = infx;
	ToPostfix();
}

string MyPostfix::GetInfix() {
	return infix;
}

vector<string> MyPostfix::GetPostfix() {
	return postfix;
}

vector<string> MyPostfix::GetOperands() {

	vector<string> op(operands.size());
	size_t i = 0;

	for (const auto& item : operands) {
		op[i++] = item.first;
	}
	return op;
}

void MyPostfix::Parse() {
	string tmp = "";
	for (char c : infix) {
		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
			if (!tmp.empty()) {
				lexems.push_back(tmp);
			}
			lexems.push_back(string{ c });
			tmp = "";
			continue;
		}
		tmp += c;
	}
	if (!tmp.empty()) {
		lexems.push_back(tmp);
	}
}

map<char, int>MyPostfix::priority = { {'sin', -1 },{'cos', -1 },{'sqrt', -1 }, {'(', 0 }, {')', 1 }, {'+', 2}, { '-', 2 }, { '*', 3 }, { '/', 3 }, {'^', 4 } };

void MyPostfix::ToPostfix() {
	Parse();
	MyStack<string> st;
	string stackItem;
	for (auto& item : lexems) {
		switch (item[0]) {
		case '(':
			st.Push(item);
			break;
		case ')':
			stackItem = st.Pop();
			while (stackItem != "(") {
				postfix.push_back(stackItem);
				stackItem = st.Pop();
			}
			break;
		case '+': case '-': case '*': case '/':case 'sin':case 'cos':case 'sqrt':case '^':
			while (!st.isEmpty()) {
				stackItem = st.Pop();
				if (priority[item[0]] <= priority[stackItem[0]]) {
					postfix.push_back(stackItem);
				}
				else {
					st.Push(stackItem);
					break;
				}
			}
			st.Push(item);
			break;
		default:
			operands.insert({ item, 0.0 });
			postfix.push_back(item);
			break;
		}
	}
	while (!st.isEmpty()) {
		stackItem = st.Pop();
		postfix.push_back(stackItem);
	}
}

double MyPostfix::Calculate(const map<string, double>& values) {

	for (auto& val : values)
	{
		try
		{
			operands.at(val.first) = val.second;
		}
		catch (out_of_range& e) {}
	}
	MyStack<double> st;
	double leftOperand, rightOperand;
	for (const string& lexem : postfix)
	{
		const char c = lexem[0];
		switch (c)
		{
		case 'sin':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			st.Push(sin(rightOperand));
			break;
		case 'cos':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			st.Push(cos(rightOperand));
			break;
		case 'sqrt':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			st.Push(sqrt(rightOperand));
			break;
		case '+':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			st.Push(leftOperand + rightOperand);
			break;
		case '-':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			st.Push(leftOperand - rightOperand);
			break;
		case '*':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			st.Push(leftOperand * rightOperand);
			break;
		case '/':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			st.Push(leftOperand / rightOperand);
			break;
		case '^':
			rightOperand = st.Pop();
			leftOperand = st.Pop();
			st.Push(pow(rightOperand, leftOperand));
			break;
		default:
			st.Push(operands[lexem]);
			break;
		}
	}
	return st.Pop();
}
















//
//int main(int argc, char* argv[])
//{
//	MyStack<int> s;
//	MyPostf calc;
//
//	size_t idx;
//	double tmp = stod(6.123, &idx);
//
//	cout << "Simple test of stack" << endl;
//	cout << "Push one element and pop one element" << endl;
//
//}
//int MyPostf::Priority(char elem)
//{
//	switch (elem)
//	{
//	case 'sin': return -1;
//	case 'cos': return -1;
//	case 'sqrt': return -1;
//	case '(': return 0;
//	case ')': return 1;
//	case '+': return 2;
//	case '-': return 2;
//	case '*': return 3;
//	case '/': return 3;
//	case '^': return 4;
//	default: throw elem;
//	}
//}
//void MyPostf::ToPostfix()
//{
//	st.Clear();
//	postfix = "";
//	string src = "(" + infix + ")";
//	char elem = '!';
//	unsigned int i = 0;
//
//	while (i < src.size())
//	{
//		postfix += " ";
//		if (src[i] >= '0' && src[i] <= '9' || src[i] == '.') 
//		{
//			postfix += src[i];
//		}
//		if (src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/' || src[i]=='sin'|| src[i] == 'cos' || src[i] == 'sqrt' || src[i] == '^' )
//		{
//			elem = st.Pop();
//			while (Priority(elem) >= Priority(src[i]))
//			{
//				postfix += elem;
//				elem = st.Pop();
//			}
//			st.Push(elem);
//			st.Push(src[i]);
//		}
//		else if (src[i] == '(') {
//			st.Push(src[i]);
//		}
//		else if (src[i] == ')') {
//			elem = st.Pop();
//			while (elem != '(') {
//				postfix += elem;
//				elem = st.Pop();
//			}
//		}
//		i++;
//	}
//}
//double MyPostf::CalcPostfix()
//{
//	unsigned int i = 0;
//	st2.Clear();
//	while (i < postfix.size()) 
//	{
//		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' ||postfix[i] == 'sin' || postfix[i] == 'cos' || postfix[i] == 'sqrt' || postfix[i] == '^')
//		{
//			double k2 = st2.Pop();
//			double k1 = st2.Pop();
//			switch (postfix[i])
//			{
//			case '+': {st2.Push(k1 + k2); break; }
//			case '-': {st2.Push(k1 + k2); break; }
//			case '*': {st2.Push(k1 + k2); break; }
//			case '/': {st2.Push(k1 + k2); break; }
//			case'sin': {st2.Push(sin(k1)); break;}
//			case'cos': {st2.Push(cos(k1)); break; }
//			case'sqrt': {st2.Push(sqrt(k1)); break; }
//			case'^': {st2.Push(pow(k1,k2)); break; }
//			}
//		}
//		else if (postfix[i] >= '0' && postfix[i] >= '9' || postfix[i] == '.')
//		{
//			size_t idx;
//			double tmp = stod(postfix[i], &idx);
//			st2.Push(stod(tmp));
//			i += idx - 1;
//		}
//		i++;
//	}
//	return 1;
//}
//double MyPostf::Calc()
//{
//	string src = "(" + infix + ")";
//	char elem = "!";
//	unsigned int i = 0;
//	st.Clear();
//	st2.Clear();
//	while (i < src.size())
//	{
//
//	}
//}