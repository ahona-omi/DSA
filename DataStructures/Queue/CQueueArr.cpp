#include <bits/stdc++.h>
using namespace std;

class CQueue{
    int front, rear,size, *arr;
public:
    CQueue(int n){
        front=rear=-1;
        size=n;
        arr= new int[size];
    } ~CQueue()    {delete[] arr;}
    bool isFull()  {return (rear+1)%size==front;}
    bool isEmpty()  {return front==-1;}
    int peek(int i){
        if(isEmpty() || i>=size){
            cout<<"!Valid\n";
            return -1;
        } return arr[i];
    }
    int Front(){
        if(isEmpty()){
            cout<<"!Element\n";
            return -1;
        } return arr[front];
    }
    int Rear(){
        if(isEmpty()){
            cout<<"!Element\n";
            return -1;
        } return arr[rear];
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        } cout << "Queue: ";
        int i = front;
        while(i!=rear){
            cout << arr[i] << " ";
            i=(i+1)%size;
        } cout <<arr[rear]<< endl;
    }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        } else{
            if (front==-1)    front=0;
            rear=(rear+1)%size;
            arr[rear] = x;
        }
    }
    void dequeue() {
        if (isEmpty())    cout << "Queue is empty" << endl;
        else if (front== rear)    front= rear= -1;
        else    front=(front+1)%size;
    }
};
int main() {
    int n=5,l;
    CQueue *head=new CQueue(n);
    for(int i=0;i<n;i++){
        cin>>l;
        head->enqueue(l);
    } head->display();
    head->dequeue();
    head->display();
    return 0;
}
