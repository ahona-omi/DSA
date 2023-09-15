#include <bits/stdc++.h>
using namespace std;

class Queue{
    int front, rear,sze,cnt, *arr;
public:
    Queue(){
        front=rear=-1;
        sze=INT_MAX;
        cnt=0;
        arr= new int[sze];
    }
    int Size()  {return cnt;}
    bool isFull()  {return rear==sze-1;}
    bool isEmpty()  {return front==-1 || front>rear;}
    int peek(int i){
        if(isEmpty() || i>=sze){
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
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        } cout << endl;
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
    void reverse() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        } int i=front, j=rear;
        while(i<j){
            int temp=arr[i];
            arr[i++]=arr[j];
            arr[j--]=temp;
        }
    }
};
int main() {
    int n=3,l;
    Queue *head=new Queue();
    for(int i=0;i<n;i++){
        cin>>l;
        head->enqueue(l);
    } head->display();
    head->reverse();
    head->display();
    head->dequeue();
    head->display();
    cout<<head->Size()<<endl;
    return 0;
}
