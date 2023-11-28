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
	string infix; // ���������� ������ infix
	vector<string> postfix; // ���������� ������� ����� postfix
	static map<char, int> priority; // ���������� ������������ �������������� ���������� priority � ������� ���� char � ���������� ���� int
	vector <string> lexems; // ���������� ������� ����� lexems
	map<string, double> operands; // ���������� �������������� ���������� operands � ������� ���� string � ���������� ���� double
	void ToPostfix(); // ���������� ������ ToPostfix() ��� ������������� ��������
	void Parse(); // ���������� ������ Parse() ��� ������������� ��������
public:
	MyPostfix(string infix); // ���������� ������������ ������ MyPostfix � ���������� ���� string
	string GetInfix(); // ���������� ������ GetInfix() � ������������ ��������� ���� string
	vector<string> GetPostfix(); // ���������� ������ GetPostfix() � ������������ ��������� ���� vector<string>
	vector <string> GetOperands(); // ���������� ������ GetOperands() � ������������ ��������� ���� vector<string>
	double Calculate(const map<string, double>& values); // ���� ����������, ���������� �� ����������� �����
};




//class MyPostf
//{
//private:
//	string infix; //������ � ��������� ������
//	string postfix; //������ � ����������� ������
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
////������� ��������� �� ��������� ����� � �����������
//void ToPostfix();
////���������� ��������� �� ����������� �����
//double CalcPostfix();
////���������� ��������� �� 1 ������ �� ���������
//double Calc();
//
//};