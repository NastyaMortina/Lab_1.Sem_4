#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

using namespace std;

const int MaxStackSize = 100;

template <class T>
class Stack
{
    T* pMem;
    int size;
    int top;
    Stack(const Stack& st) {}
    Stack& operator=(const Stack& st) {}
public:
    Stack(int _size)
    {
        size = _size;
        top = -1;
        if ((size < 1) || (size > MaxStackSize))
            throw size;
        pMem = new T[size];
    }

    ~Stack()
    {
        if (pMem != NULL)
            delete[] pMem;

    }

    bool isEmpty() const 
    {
        return (top == -1);
    }

    bool isFull() const 
    {
        return (top == size - 1);
    }

    void push(const T& val)
    {
        if (isFull())
            throw "Error";
        pMem[++top] = val;
    }

    T Pop() 
    {
        if (isEmpty())
            throw "Error";
        return pMem[top--];
    }

    T Top()
    {
        if (isEmpty())
            throw (top);
        return pMem[top - 1];
    }
};

#endif
