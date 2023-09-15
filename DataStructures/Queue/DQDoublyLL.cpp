#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *nxt, *prev;
    Node(int x){
        data=x;
        prev=nxt=NULL;
    }
};
class dQueue{
    Node *front, *rear;
    int Size;
public:
    dQueue(){
        front=rear=NULL;
        Size=0;
    }
    int size()  {return Size;}
    bool isEmpty()  {return front==NULL;}
    void eraseAll(){
        rear=NULL;
        while(front!=NULL){
            Node *temp=front;
            front=front->nxt;
            free(temp);
        } Size=0;
    }
    int getFront(){
        if(isEmpty())   return -1;
        return front->data;
    }
    int getRear(){
        if(isEmpty())   return -1;
        return rear->data;
    }
    void display(){
        if(isEmpty())   cout<<"!Element\n";
        else{
            cout<<"Ber kor: ";
            Node *i=front;
            while(i!=rear){
                cout<<i->data<<" ";
                i=i->nxt;
            } cout<<i->data<<endl;
        }
    }
    void enQFront(int x){
        Node *newN= new Node(x);
        if(newN==NULL)  cout<<"!Enqueue\n";
        else{
            if(front==NULL)    rear=front=newN;
            else{
                newN->nxt=front;
                front->prev=newN;
                front=newN;
            } Size++;
        }
    }
    void enQRear(int x){
        Node *newN= new Node(x);
        if(newN==NULL)  cout<<"!Enqueue\n";
        else{
            if(rear==NULL)    rear=front=newN;
            else{
                newN->prev=rear;
                rear->nxt=newN;
                rear=newN;
            } Size++;
        }
    }
    void deQFront(){
        if(isEmpty())   cout<<"!Element\n";
        else{
            Node *temp=front;
            front=front->nxt;
            if(front==NULL)    rear=NULL;
            else    front->prev=NULL;
            free(temp);
            Size--;
        }
    }
    void deQRear(){
        if(isEmpty())   cout<<"!Element\n";
        else{
            Node *temp=rear;
            rear=rear->prev;
            if(rear==NULL)    front=NULL;
            else    rear->nxt=NULL;
            free(temp);
            Size--;
        }
    }
};
void reverse(dQueue* &oldDeq, dQueue* &newDeq) {
    while(!oldDeq->isEmpty()) {
        int backElem = oldDeq->getRear();
        oldDeq->deQRear();
        newDeq->enQRear(backElem);
    }
}
int main() {
    dQueue *head=new dQueue(),*tail=new dQueue();
    head->enQFront(69);
    head->enQRear(420);
    head->enQFront(0);
    head->enQFront(3);
    head->enQRear(10);
    head->enQRear(-20);
    head->display();
    head->deQFront();
    head->deQRear();
    head->display();
    reverse(head,tail);
    tail->display();
    cout<<head->isEmpty()<<endl;
    head->eraseAll();
    head->display();
    cout<<head->isEmpty()<<endl;
    return 0;
}
