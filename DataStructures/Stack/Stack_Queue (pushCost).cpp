#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Queue{
    int front, rear,sze,cnt, *arr;
public:
    Queue(){
        front=rear=-1;
        sze=100;
        cnt=0;
        arr= new int[sze];
    }
    int Size()  {return cnt;}
    bool isFull()  {return rear==sze-1;}
    bool isEmpty()  {return front==-1 || front>rear;}
    int Front(){
        if(isEmpty()){
            cout<<"!Element\n";
            return -1;
        } return arr[front];
    }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        } if (front==-1)    front++;
        rear++;
        cnt++;
        arr[rear] = x;
    }
    void dequeue() {
        if (isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        } if (front== rear)    front= rear= -1;
        else    front++;
        cnt--;
    }
};

class Stack_Queue{
    int N;
    Queue *q1, *q2;
public:
    Stack_Queue(){
        N=0;
        q1= new Queue();
        q2= new Queue();
    }
    void push(int x){
        q2->enqueue(x);
        N++;
        while(!q1->isEmpty()){
            q2->enqueue(q1->Front());
            q1->dequeue();
        } Queue *temp=q1;
        q1=q2;
        q2=temp;
    }
    void pop(){
        q1->dequeue();
        N--;
    }
    bool Empty()    {return q1->isEmpty();}
    int Top()   {return q1->Front();}
    int Size()  {return N;}
    void display() {
        if (q1->isEmpty()) {
            return;
        }
        Queue *temp = new Queue();
        while (!q1->isEmpty()) {
            int element = q1->Front();
            temp->enqueue(element);
            cout << element << " ";
            q1->dequeue();
        }
        while (!temp->isEmpty()) {
            int element = temp->Front();
            q1->enqueue(element);
            temp->dequeue();
        }
        cout << endl;
        delete temp;
    }
    void reverse(Stack_Queue *s){
        if (s->Empty())    return;
        Queue *qu1 = new Queue();
        Queue *qu2 = new Queue();
        while (!s->Empty()) {
            qu1->enqueue(s->Top());
            s->pop();
        } while (!qu1->isEmpty()) {
            qu2->enqueue(qu1->Front());
            qu1->dequeue();
        } while (!qu2->isEmpty()) {
            s->push(qu2->Front());
            qu2->dequeue();
        } delete qu1;
        delete qu2;
    }
};


int main() {
    Stack_Queue *q=new Stack_Queue();
    q->push(69);
    q->push(420);
    q->push(0);
    q->push(-69);
    q->push(3);
    
    q->display();
    cout<<"REVERSE\n";
    q->reverse(q);
    cout<<"POP\n";
    //q->pop();
    q->display();
    return 0;
}
