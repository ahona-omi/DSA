#ifndef CIRCULAR_QUEUE_HPP
#define CIRCULAR_QUEUE_HPP

#include <bits/stdc++.h>
using namespace std;

class CirQ
{
private:
    int ar[10000];
    int start;
    int end;
    int count;
    int limit;

public:
    CirQ(int n);
    void push(int n);
    int pop();
    int front();
    bool isEmpty();
    bool isFull();
    void display();
    void clear();
    int size();
};

CirQ::CirQ(int sz)
{
    this->start = 0;
    this->end = 0;
    this->count = 0;
    this->limit = sz;
}

void CirQ::push(int n)
{
    if (this->count + 1 > this->limit)
    {
        cout << "Queue size overloaded\n";
        return;
    }

    this->ar[this->end] = n;
    (this->end)++;
    (this->end) %= (this->limit);
    (this->count)++;
}

int CirQ::pop()
{
    int val = this->ar[this->start];

    if (this->start == this->end)
    {
        cout << "Nothing to pop!!\n";
        return -1;
    }

    (this->start)++;
    (this->start) %= (this->limit);
    (this->count)--;

    return val;
}

int CirQ::front()
{
    return (this->ar[this->start]);
}

bool CirQ::isEmpty()
{
    return (this->count == 0);
}

bool CirQ::isFull()
{
    return (this->count == this->limit);
}

void CirQ::display()
{
    cout << "Display... ";

    for (int i = this->start, j = 0; j < (this->count); i++, i %= this->limit, j++)
    {
        cout << this->ar[i] << " ";
    }
    cout << endl;
}

int CirQ::size()
{
    return (this->count);
}

void CirQ::clear()
{
    this->start = this->end = this->count = 0;
    memset(ar, sizeof(ar) / sizeof(ar[0]), 0);
}

#endif