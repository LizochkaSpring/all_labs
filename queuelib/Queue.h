#pragma once
#include <iostream>

const int MaxQueueSize = 100;
const int MinQueueSize = 1;


template <class T>
class Queue {
	int begin; // � ������ �������� �������, � ������� �������� ������ ������� �������
	int end; // - ������ �������� �������, � ������� �������� ��������� ������� �������
	size_t size; // � ������ ���������� ������
	T* pMem; // � ��������� �� ������, ���������� ��� ���������� ������
	int cnt; // - (count) ���������� ����������� � ������� ��������

public:
	Queue() {
		begin = 0;
		end = 0;
		size = 0;
		cnt = 0;
		pMem = new T[size];
	}

	~Queue() {
		delete[] pMem;
	}

	Queue(size_t s) {
		if (s < MinQueueSize || s > MaxQueueSize)
			throw "������������ ������ �������";
		size = s;
		begin = 0;
		end = 0;
		cnt = 0;
		pMem = new T[size];
	}
	
	size_t GetSize() {
		return cnt;
	}

	bool IsEmpty() { //- ��������� ������� �� �������
		if (cnt == 0)
			return true;
		return false;
	}

	bool IsFull() { //- ��������� ������� �� �������
		if (cnt == size)
			return true;
		return false;
	}

	void Push(T val) { //�������� �������
		if (IsFull())
			throw "������� ���������";
		pMem[end++] = val;
		cnt++;
		end %= size; // ��������� ��������� ������� ������� "end" �� ������ �������, 
		//����� �������������, ��� �� �������� � �������� ���������� ��������
	}

	T Pop() { //������� �������
		if (IsEmpty()) {
			throw "������� �����";
		}
		T tmp = pMem[begin];
		begin = (begin + 1) % size;
		cnt--;
		return tmp;
	}

	T GetFirst() { //��������� �������� �� ������� "pMem" �� ������� "begin"
		if (IsEmpty()) {
			throw "������� �����";
		}
		return pMem[begin];
	}

	T GetEnd() { //��������� �������� �� ������� "pMem" �� ������� "end"
		if (IsFull()) {
			throw "������� ���������";
		}
		return pMem[end];
	}
};