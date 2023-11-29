#pragma once
#define __MyPostf_h__
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include "MyStack.h"
#include <stdexcept>
#include <math.h>
#include <string>
#include <cstdlib>

using namespace std;



class MyPostfix
{
	string infix; // объ€вление строки infix
	vector<string> postfix; // объ€вление вектора строк postfix
	static map<char, int> priority; // объ€вление статического ассоциативного контейнера priority с ключами типа char и значени€ми типа int
	vector <string> lexems; // объ€вление вектора строк lexems
	map<string, double> operands; // объ€вление ассоциативного контейнера operands с ключами типа string и значени€ми типа double
	void ToPostfix(); // объ€вление метода ToPostfix() без возвращаемого значени€
	void Parse(); // объ€вление метода Parse() без возвращаемого значени€ 
	//реализованы методы дл€ разбиени€ инфиксного выражени€ на лексемы
public:
	MyPostfix();
	MyPostfix(std::string infix); // объ€вление конструктора класса MyPostfix с параметром типа string
	string GetInfix(); // объ€вление метода GetInfix() с возвращаемым значением типа string
	vector<string> GetPostfix(); // объ€вление метода GetPostfix() с возвращаемым значением типа vector<string>
	vector <string> GetOperands(); // объ€вление метода GetOperands() с возвращаемым значением типа vector<string>
	double Calculate(const map<string, double>& values); // ¬вод переменных, вычисление по постфиксной форме
};

MyPostfix::MyPostfix()
{

}

MyPostfix::MyPostfix(std::string infx) {
	if (infx.empty())
		throw "Stack is empty"; // стек пуст
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
//sin = s
//cos = c
//sqrt = q
void MyPostfix::Parse() { //реализован метод дл€ разбиени€ инфиксного выражени€ на лексемы
	string tmp = "";
	for (char c : infix) {
		if (c == 's' || c == 'c' || c == 'q' || c == '^' || c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
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
	{'s', -1 },
	{'c', -1 },
	{'q', -1 },
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
		case '+': case '-': case '*': case '/':case 's':case 'c':case 'q':case '^':
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
		case 's':
			rightOperand = st.Pop();
			st.Push(sin(rightOperand));
			break;
		case 'c':
			rightOperand = st.Pop();
			st.Push(cos(rightOperand));
			break;
		case 'q':
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