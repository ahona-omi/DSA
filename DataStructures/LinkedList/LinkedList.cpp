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
void traverse(Node *head){
    cout<<"Linked List: ";
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->nxt;
    } cout<<endl;
}
//INSERTION
Node *insertHead(Node *head, int x){
    Node *ptr=new Node(x);
    ptr->nxt=head;
    return ptr;
}
void insertTail(Node *head, int x){
    Node *ptr=new Node(x);
    if(head==NULL)     head=ptr;
    else{
        Node *temp=head;
        while(temp->nxt!=NULL)     temp=temp->nxt;
        temp->nxt=ptr;
    }
}
void insertIndex(Node *head, int x, int index){
    Node *p=head, *ptr=new Node(x);
    int i=0;
    while(i!=index-1){
        p=p->nxt;
        i++;
    } ptr->nxt=p->nxt;
    p->nxt=ptr;
}
void insertAfterNode(Node *head, Node *prevNode, int x){
    Node *ptr=new Node(x);
    ptr->nxt=prevNode->nxt;
    prevNode->nxt=ptr;
}
//DELETION
Node *delHead(Node *head){
    Node *ptr=head;
    head=head->nxt;
    free(ptr);
    return head;
}
void delIndex(Node *head, int index){
    Node *p=head, *q=head->nxt;
    for(int i=0;i<index-1;i++){
        p=p->nxt;
        q=q->nxt;
    } p->nxt=q->nxt;
    free(q);
}
void delValue(Node *head, int val){
    Node *p=head, *q=head->nxt;
    while(q->data!=val && q->nxt!=NULL){
        p=p->nxt;
        q=q->nxt;
    } if(q->data==val){
        p->nxt=q->nxt;
        free(q);
    } else  cout<<"No item -_-\n";
}
//REVERSE LINKED LIST
void shojaRevrse(Node* &head){
    if(head==NULL || head->nxt==NULL)   return;
    Node *prev=NULL, *curnt=head, *next=head;
    while(next!=NULL){
        next=next->nxt;
        curnt->nxt=prev;
        prev=curnt;
        curnt=next;
    } head=prev;
}
Node *teraReverse(Node* &head){
    if(head==NULL || head->nxt==NULL)   return head;
    Node *newN=teraReverse(head->nxt);
    head->nxt->nxt=head;
    head->nxt=NULL;
    return newN;
}
int main() {
    int n=3,l,frstData;
    Node *head=NULL, *tail=NULL;
    // cout<<"Koyta dhukabi: ";
    // cin>>n;
    cout<<"Prothome ki dhukabi: ";
    cin>>frstData;
    head=new Node(frstData);
    for(int i=1;i<n;i++){
        cin>>l;
        insertTail(head,l);
    }
    cout<<"Mathai dhuka\n";
    head= insertHead(head,69);
    traverse(head);
    cout<<"Ghurai de\n";
    Node *newH=teraReverse(head);
    traverse(newH);
    return 0;
}
