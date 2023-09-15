/*implements a circular double-ended queue 
(deque) using an array*/

#include <bits/stdc++.h>
using namespace std;

class DEQueue{
    int front,rear,size;
    int *arr;
public:
    DEQueue(int n){
        front = rear = -1;
        size=n;
        arr=new int[size];
    }
    void enqueueFront(int x){
        if (!isFull()){
            if (front == -1){
                front = rear = 0;
                arr[front] = x;
            } else{
                if (front == 0)    front = size - 1;
                else    front--;
                arr[front] = x;
            }
        } else  cout<<"Overflow!\n";
    }
    void enqueueRear(int x){
        if (!isFull()){
            if (rear == -1){
                front = rear = 0;
                arr[rear] = x;
            } else{
                if (rear == size - 1)    rear = 0;
                else    rear++;
                arr[rear] = x;
            }
        } else  cout<<"Overflow!\n";
    }
    void dequeueFront(){
        if (!isEmpty()){
            if (front == rear)    front = rear = -1;
            else{
                if (front == size - 1)    front = 0;
                else    front++;
            }
        } else cout<<"NO element!\n";
    }
    void dequeueRear(){
        if (!isEmpty()){
            if (front == rear)    front = rear = -1;
            else{
                if (rear == 0)    rear = size - 1;
                else    rear--;
            }
        } else cout<<"NO element!\n";
    }
    int getFront(){
        if (!isEmpty())    return arr[front];
        return -1;
    }
    int getRear(){
        if (!isEmpty())    return arr[rear];
        return -1;
    }
    void display(){
        if (isEmpty())   {cout << "Queue is empty." << endl;}
        else{
            int i=front;
            cout << "Circular Queue: ";
            while (i != rear){
                cout << arr[i] << " ";
                i=(i+1)%size;
            } cout <<arr[rear]<< endl;
        }
    }
    bool isFull()   {return ((rear+1)%size==front);}
    bool isEmpty()   {return (front==-1);}
};

int main(){
    int n=5, y;
    //cin >> n;
    DEQueue q(n);
    //cout << "Enter queue:\n";
    // for (int i = 0; i < n; i+=2){
    //     if(i%4==0 || i%4==1){
    //         cin >> y;
    //         q.enqueueFront(y);
    //     } else if(i%4==2 || i%4==3){
    //         cin >> y;
    //         q.enqueueRear(y);
    //     }
    // }
    q.enqueueFront(3);
    q.enqueueRear(4);
    q.enqueueRear(5);
    q.dequeueRear();
    q.enqueueFront(2);
    q.dequeueFront();
    cout << q.isEmpty() << endl;
    q.display();
    return 0;
}