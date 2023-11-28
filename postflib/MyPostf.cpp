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
		if (c == 'sin' || c == 'cos' || c == 'sqrt' || c == '^' || c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
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

map<char, int>MyPostfix::priority = { 
	{'sin', -1 },
	{'cos', -1 },
	{'sqrt', -1 }, 
	{'(', 0 }, 
	{')', 1 }, 
	{'+', 2}, 
	{ '-', 2 }, 
	{ '*', 3 }, 
	{ '/', 3 }, 
	{'^', 4 } 
};

void MyPostfix::ToPostfix() {
	Parse();
	MyStack<string> st(100);
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
	MyStack<double> st(100);
	double leftOperand, rightOperand;
	for (const string& lexem : postfix)
	{
		const char c = lexem[0];
		switch (c)
		{
		case 'sin':
			rightOperand = st.Pop();
			st.Push(sin(rightOperand));
			break;
		case 'cos':
			rightOperand = st.Pop();
			st.Push(cos(rightOperand));
			break;
		case 'sqrt':
			rightOperand = st.Pop();
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