#include <bits/stdc++.h>
using namespace std;
const int N=100;
class Stack{
    int top, cnt, *arr;
public:
    Stack(){
        top=-1;
        cnt=0;
        arr= new int[N];
    }
    int Size()  {return cnt;}
    bool isEmpty()  {return top==-1;}
    bool isFull()  {return top==N-1;}
    int Top(){
        if(isEmpty()){
            cout<<"!Element\n";
            return -1;
        } return arr[top];
    }
    void push(int x) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        } arr[++top] = x;
        cnt++;
    }
    void pop() {
        if (isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        } top--;
        cnt--;
    }
};
class Queue_Stack{
    int cnt,size;
    Stack *s1,*s2;
public:
    Queue_Stack(){
        size=N;
        cnt=0;
        s1= new Stack();
        s2= new Stack();
    }
    int Size()  {return cnt;}
    bool Empty()    {return (s1->isEmpty() && s2->isEmpty());}
    void enqueue(int x) {
        s1->push(x);
        cnt++;
    }
    int dequeue() {
        if(Empty()){
            cout<<"Empty\n";
            return -1;
        } if(s2->isEmpty()){
            while(!s1->isEmpty()){
                s2->push(s1->Top());
                s1->pop();
            }
        } int val= s2->Top();
        s2->pop();
        cnt--;
        return val;
    }
    void display() {
        if (Empty()) {
            cout << "Queue is empty\n";
            return;
        } cout << "Elements in the queue are: ";
        while (!s1->isEmpty()) {
            s2->push(s1->Top());
            s1->pop();
        } while (!s2->isEmpty()) {
            cout << s2->Top() << " ";
            s1->push(s2->Top());
            s2->pop();
        } cout << endl;
    }
    // void reverse() {
    //     while (!Empty()) {
    //         s2->push(dequeue());
    //     }
    //     while (!s2->isEmpty()) {
    //         s1->push(s2->Top());
    //         s2->pop();
    //     } int i=0;
    //     while (!s2->isEmpty()) {
    //         s2->push(s1->Top());
    //         s1->pop();
    //     } 
    // }
};

int main() {
    Queue_Stack *q=new Queue_Stack();
    q->enqueue(69);
    q->enqueue(420);
    q->enqueue(0);
    q->enqueue(-69);
    q->enqueue(3);
    cout<<"dekha"<<endl;
    q->display();
    // cout<<"ulta"<<endl;
    // q->reverse();
    q->display();
    // int x=q->dequeue();
    // cout<<x<<endl;
    // cout<<"Again dekha"<<endl;
    // q->display();
    return 0;
}
