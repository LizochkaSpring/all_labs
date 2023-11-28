#pragma once
#define __MyPostf_h__
#include <iostream>
#include <string>
#include "MyStack.h"
#include <map>
#include <vector>

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
public:
	MyPostfix(string infix); // объ€вление конструктора класса MyPostfix с параметром типа string
	string GetInfix(); // объ€вление метода GetInfix() с возвращаемым значением типа string
	vector<string> GetPostfix(); // объ€вление метода GetPostfix() с возвращаемым значением типа vector<string>
	vector <string> GetOperands(); // объ€вление метода GetOperands() с возвращаемым значением типа vector<string>
	double Calculate(const map<string, double>& values); // ¬вод переменных, вычисление по постфиксной форме
};




//class MyPostf
//{
//private:
//	string infix; //—трока в инфиксной записи
//	string postfix; //—трока в постфиксной записи
//	MyStack<char> st;
//	MyStack<double> st2;
//	int Priority(char elem);
//public:
//	MyPostf(): st(100), st2(100)
//	{
//		infix = "";
//		postfix = "";
//	}
//	string GetExperession() 
//	{
//		return infix;
//	}
//	void SetExpression(string expr)
//	{
//		infix = expr;
//	}
//	string GetPostfix()
//	{
//	return postfix;
//	}
////ѕеревод выражени€ из инфиксной формы в постфиксную
//void ToPostfix();
////¬ычисление выражени€ по постфиксной форме
//double CalcPostfix();
////¬ычисление выражени€ за 1 проход по инфиксной
//double Calc();
//
//};