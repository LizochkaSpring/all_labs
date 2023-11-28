#pragma once
#include <iostream>

template<typename T>
class MyStack
{
protected:
    T* pMem;
    int size;
    int first;
public:
    MyStack(int _size = 100);
    MyStack(const MyStack<T>& st);
    MyStack(MyStack<T>&& st);
    ~MyStack();

    MyStack<T>& operator=(const MyStack<T>& st);
    MyStack<T>& operator=(MyStack<T>&& st);
    bool operator==(const MyStack<T>& st) const;
    bool operator!=(const MyStack<T>& st) const;

    bool isEmpty(); //проверяет, пуст ли стек
    bool isFull(); //проверяет, заполнен ли стек
    void Push(T elem); //позволяет «протолкнуть» элемент в начало стека
    T Pop(); //позволяет удалить элемент из начала стека
};

template<typename T>
inline MyStack<T>::MyStack(int _size)
{
    if (_size > 0)
    {
        size = _size;
        first = 0;
        pMem = new T[size];
    }
    else
    {
        throw "Сбой в стеке инициализации";
    }
}

template<typename T>
inline MyStack<T>::MyStack(const MyStack<T>& st)
{
    if (st.pMem == nullptr)
    {
        pMem = nullptr;
        size = 0;
        first = 0;
    }
    else
    {
        size = st.size;
        first = st.first;
        pMem = new T[size];
        for (int i = 0; i < size; i++)
        {
            pMem[i] = st.pMem[i];
        }
    }
}

template<typename T>
inline MyStack<T>::MyStack(MyStack<T>&& st)
{
    size = st.size;
    first = st.first;
    pMem = st.pMem;

    st.size = 0;
    st.first = 0;
    st.pMem = nullptr;
}

template<typename T>
inline MyStack<T>::~MyStack()
{
    if (pMem != nullptr)
    {
        delete[] pMem;
        pMem = nullptr;
    }
    size = 0;
    first = 0;
}

template<typename T>
inline MyStack<T>& MyStack<T>::operator=(const MyStack<T>& st)
{
    if (this == &st)
    {
        return *this;
    }
    if (pMem != nullptr)
    {
        delete[] pMem;
    }
    if (st.pMem == nullptr)
    {
        pMem = nullptr;
        size = 0;
        first = 0;
    }
    else
    {
        size = st.size;
        first = st.first;
        pMem = new T[size];
        for (int i = 0; i < size; i++)
        {
            pMem[i] = st.pMem[i];
        }
    }
    return *this;
}

template<typename T>
inline MyStack<T>& MyStack<T>::operator=(MyStack<T>&& st)
{
    if (this == &st)
    {
        return *this;
    }
    if (pMem != nullptr)
    {
        delete[] pMem;
    }
    pMem = st.pMem;
    size = st.size;
    first = st.first;

    st.pMem = nullptr;
    st.size = 0;
    st.first = 0;
    return *this;
}

template<typename T>
inline bool MyStack<T>::operator==(const MyStack<T>& st) const
{
    if (size != st.size || first != st.first)
    {
        return false;
    }
    for (int i = 0; i < size; i++)
    {
        if (pMem[i] != st.pMem[i])
        {
            return false;
        }
    }
    return true;
}

template<typename T>
inline bool MyStack<T>::operator!=(const MyStack<T>& st) const
{
    if (size != st.size || first != st.first)
    {
        return true;
    }
    for (int i = 0; i < size; i++)
    {
        if (pMem[i] != st.pMem[i])
        {
            return true;
        }
    }
    return false;
}

template<typename T>
inline bool MyStack<T>::isEmpty()
{
    if (first == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<typename T>
inline bool MyStack<T>::isFull()
{
    if (size == first)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<typename T>
inline void MyStack<T>::Push(T elem)
{
    if (isFull())
    {
        throw "Полный стек сбоев";
    }
    pMem[first] = elem;
    first += 1;
}

template<typename T>
inline T MyStack<T>::Pop()
{
    if (isEmpty())
    {
        throw "Стек сбоев пуст";
    }
    first--;
    return pMem[first];
}