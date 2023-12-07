#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
	Queue<int> a(3);
	a.Push(1);
	a.Push(2);
	a.Push(3);
	for (int i = 0; i < 3; i++) {
		cout << a.Pop() << endl;
	}
}
