#pragma once
#define __MyPostf_h__
#include <iostream>
#include <string>
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
	MyPostfix();
	MyPostfix(string infix); // ���������� ������������ ������ MyPostfix � ���������� ���� string
	string GetInfix(); // ���������� ������ GetInfix() � ������������ ��������� ���� string
	vector<string> GetPostfix(); // ���������� ������ GetPostfix() � ������������ ��������� ���� vector<string>
	vector <string> GetOperands(); // ���������� ������ GetOperands() � ������������ ��������� ���� vector<string>
	double Calculate(const map<string, double>& values); // ���� ����������, ���������� �� ����������� �����
};