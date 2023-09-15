#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *nxt;
    Node(int x){
        data=x;
        nxt=NULL;
    }
};
class Queue{
    Node *front, *rear;
public:
    Queue()   {front=rear=NULL;}
    bool isEmpty()  {return front==NULL && rear==NULL;}
    int Front(){
        if(isEmpty()){
            cout<<"!Element\n";
            return -1;
        } return front->data;
    }
    int Rear(){
        if(isEmpty()){
            cout<<"!Element\n";
            return -1;
        } return rear->data;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        } cout << "Queue: ";
        Node *temp=front;
        while(temp!=NULL){
            cout << temp->data << " ";
            temp=temp->nxt;
        } cout << endl;
    }
    void enqueue(int x) {
        Node *newN= new Node(x);
        if (isEmpty())  front=rear=newN;
        else{
            rear->nxt=newN;
            rear=newN;
        }
    }
    void dequeue() {
        if (isEmpty())    cout << "Queue is empty" << endl;
        else{
            Node *newN=front;
            front=front->nxt;
            free(newN);
        }
    }
    void reverse() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        } Node* prev = NULL, *curr = front, *next = NULL;
        rear = curr;
        while (curr != NULL) {
            next = curr->nxt;
            curr->nxt = prev;
            prev = curr;
            curr = next;
        } front = prev;
    }
};
int main() {
    Queue *q=new Queue();
    q->enqueue(69);
    q->enqueue(420);
    q->enqueue(0);
    q->enqueue(-69);
    q->enqueue(3);
    
    q->display();
    q->reverse();
    q->display();
    q->dequeue();
    q->display();
    return 0;
}
