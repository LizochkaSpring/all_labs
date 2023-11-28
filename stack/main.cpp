#include <iostream>
#include "MyStack.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	MyStack<int> a(10);
	a.Push(1);
	a.Push(2);
	a.Push(3);


	while (!a.isEmpty()) {
		cout << a.Pop() << endl;
	}
}
