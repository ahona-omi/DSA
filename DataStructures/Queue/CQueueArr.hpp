#ifndef CQUEUEARR_HPP
#define CQUEUEARR_HPP

#include <bits/stdc++.h>
using namespace std;

class CQueue{
    int front, rear,limit,cnt, *arr;
public:
    CQueue(int n);
    ~CQueue();
    bool isFull();
    bool isEmpty();
    int Front();
    void display();
    void push(int x) ;
    int pop();
    void clear();
    int size();
};
CQueue::CQueue(int n){
        this->front=this->rear=-1;
        this->limit=n;
        this->cnt=0;
        this->arr= new int[this->limit];
}

CQueue::~CQueue()    {delete[] this->arr;}

bool CQueue::isFull()  {return (this->rear+1)%this->limit==this->front;}

bool CQueue::isEmpty()  {return this->front==-1;}

int CQueue::Front()     {return this->arr[this->front];}

void CQueue::display() {
    cout << "Queue: ";
    int i = this->front;
    while(i!=this->rear){
        cout << this->arr[i] << " ";
        i=(i+1)%this->limit;
    } cout <<this->arr[this->rear]<< endl;
}

void CQueue::push(int x) {
    if (isFull()) {
        cout << "Queue is full" << endl;
        return;
    }
    if (this->front==-1)    this->front=0;
    this->rear=(this->rear+1)%this->limit;
    this->arr[this->rear] = x;
    this->cnt++;
}

int CQueue::pop() {
    int a=this->arr[this->front];
    if (this->front== this->rear)    this->front= this->rear= -1;
    else    this->front=(this->front+1)%this->limit;
    this->cnt--;
    return a;
}

void CQueue::clear(){
    this->front=this->rear=-1;
    this->cnt=0;
    memset(arr, sizeof(arr) / sizeof(arr[0]), 0);
}

int CQueue::size()  {return this->cnt;}

#endif