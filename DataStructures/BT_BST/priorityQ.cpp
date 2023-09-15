#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int p,info;
    Node *l;
};
class priorityQ{
    Node *f;
public:
    priorityQ()    {f=NULL;}
    void push(int i, int P){
        Node *t, *q;
        t=new Node();
        t->info=i;
        t->p=P;
        if(f==NULL || P<f->p){
            t->l=f;
            f=t;
        } else {
            q=f;
            while(q->l!=NULL && q->l->p<=P)    q=q->l;
            t->l=q->l;
            q->l=t;
        }
    }
    void pop(){
        Node *t;
        if(f==NULL)    cout<<"No priority queue available\n";
        else{
            t=f;
            cout<<"Delete item "<<t->info<<endl;
            f=f->l;
            free(t);
        }
    }
    void show(){
        Node *ptr=f;
        if(f==NULL)    cout<<"No priority queue available\n";
        else{
            cout<<"Priority Queue\n";
            while(ptr!=NULL){
                cout<<"("<<ptr->p<<")"<<ptr->info<<endl;
                ptr=ptr->l;
            } cout<<endl;
        }
    }
};
int main(){
    priorityQ pq;

    // Testing push operation
    pq.push(1, 2);
    pq.push(2, 1);
    pq.push(3, 3);

    // Testing show operation
    pq.show();

    // Testing pop operation
    pq.pop();
    pq.show();
    return 0;
}