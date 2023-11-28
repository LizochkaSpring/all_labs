#include <iostream>
#include <string>
#include "MyPostf.h"
#include <map>
#include <vector>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string expression;
	cout << "������� ��������� ��� ��������: ";
	cin >> expression;
	MyPostfix expr(expression);
	cout << "�������������� ���������: " << expr.GetInfix() << endl;
	const auto postfix = expr.GetPostfix();
	for (const auto& lexem : postfix)
	{
		cout << lexem << ' ';
	}
	cout << endl;
	//cout << "����������� �����: " << expr.GetPostfix() << endl;
	vector<string> operands = expr.GetOperands();
	map<string, double> values;
	double val;
	for (const auto& op : operands)
	{
		try {
			double val = stod(op);
			values[op] = val;
		}
		catch (...) { // ����� ����� ���
			cout << "������� �������� " << op << ": ";
			cin >> val;
			values[op] = val;
		}
	}
	cout << "���������: " << expr.Calculate(values) << endl;
	return 0;
}
