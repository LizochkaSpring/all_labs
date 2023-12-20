#pragma once
#include <iostream>

const int MaxQueueSize = 100;
const int MinQueueSize = 1;


template <class T>
class MyQueue {
	int MaxSize; // - максимальный размер
	int begin; // Ц индекс элемента массива, в котором хранитс€ первый элемент очереди
	int end; // - индекс элемента массива, в котором хранитс€ последний элемент очереди
	size_t size; // Ц размер выделенной пам€ти
	T* pMem; // Ц указатель на пам€ть, выделенную дл€ кольцевого буфера
	int cnt; // - (count) количество заполненных в очереди значений

public:
	MyQueue() {
		begin = 0;
		end = 0;
		size = 0;
		cnt = 0;
		MaxSize = 0;
		pMem = new T[size];
	}

	~MyQueue() {
		delete[] pMem;
	}

	MyQueue(size_t s) {
		if (s < MinQueueSize || s > MaxQueueSize)
			throw "Ќеправильный размер очереди";
		size = s;
		begin = 0;
		end = 0;
		cnt = 0;
		pMem = new T[size];
	}
	
	size_t GetSize() {
		return cnt;
	}

	int GetMaxSize() {
		return MaxSize;
	}

	bool IsEmpty() { //- проверить очередь на пустоту
		if (cnt == 0)
			return true;
		return false;
	}

	bool IsFull() { //- проверить очередь на полноту
		if (cnt == size)
			return true;
		return false;
	}

	void Push(T val) { //добавить элемент
		if (IsFull())
			throw "ќчередь заполнена";
		pMem[end++] = val;
		cnt++;
		end %= size; // выполн€ет модульное деление индекса "end" на размер массива, 
		//чтобы гарантировать, что он остаетс€ в пределах допустимых значений
	}

	T Pop() { //удалить элемент
		if (IsEmpty()) {
			throw "ќчередь пуста";
		}
		T tmp = pMem[begin];
		begin = (begin + 1) % size;
		cnt--;
		return tmp;
	}

	T GetFirst() { //извлекает значение из массива "pMem" по индексу "begin"
		if (IsEmpty()) {
			throw "ќчередь пуста";
		}
		return pMem[begin];
	}

	T GetEnd() { //извлекает значение из массива "pMem" по индексу "end"
		if (IsFull()) {
			throw "ќчередь заполнена";
		}
		return pMem[end];
	}
};