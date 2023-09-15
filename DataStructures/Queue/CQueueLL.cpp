#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *nxt;
};
class CQueue{
    Node *front, *rear;
    int size;
public:
    CQueue(){
        front=rear=NULL;
        size=0;
    }
    int Size()  {return size;}
    int Front(){
        if(front=NULL){
            cout<<"!Element\n";
            return -1;
        } return front->data;
    }
    int Rear(){
        if(rear=NULL){
            cout<<"!Element\n";
            return -1;
        } return rear->data;
    }
    void display() {
        if (front==NULL) {
            cout << "Queue is empty" << endl;
            return;
        } else{
            cout << "Queue: ";
            Node *temp=front;
            do{
                cout << temp->data << " ";
                temp=temp->nxt;
            } while(temp!=front);
        } cout << endl;
    }
    void enqueue(int x) {
        Node *newN= new Node();
        newN->data=x;
        newN->nxt=NULL;
        if (front==NULL)    front=rear=newN;
        else{
            rear->nxt=newN;
            rear=newN;
        } rear->nxt=front;
        size++;
    }
    void dequeue() {
        if (front==NULL)    cout << "Queue is empty" << endl;
        else if(front==rear){
            delete front;
            front=rear=NULL;
        } else{
            Node *newN=front;
            front=front->nxt;
            rear->nxt=front;
            delete newN;
        } size--;
    }
    void reverse(CQueue *q) {
        if (q->Size() <= 1) {
            return;
        } Node *prev = q->rear, *current = q->front, *next = current->nxt;
        do {
            current->nxt = prev;
            prev = current;
            current = next;
            next = current->nxt;
        } while (current != q->front);
        current->nxt = prev;
        q->front = q->rear;
        q->rear = current;
    }
};

int main() {
    CQueue *q=new CQueue();
    q->enqueue(69);
    q->enqueue(420);
    q->enqueue(0);
    q->enqueue(-69);
    q->enqueue(3);
    
    q->display();
    q->reverse(q);
    q->display();
    q->dequeue();
    q->display();
    return 0;
}
