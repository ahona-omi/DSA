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
void traverse(Node *head){
    cout<<"Linked List: ";
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->nxt;
    } cout<<endl;
}
//INSERTION
void insertHead(Node* &head, int x){
    Node *ptr=new Node(x);
    ptr->nxt=head;
    if(head!=NULL)     head->prev=ptr;
    head=ptr;
}
void insertTail(Node* &head, int x){
    if(head==NULL)     insertHead(head,x);
    else{
        Node *ptr=new Node(x), *temp=head;
        while(temp->nxt!=NULL)     temp=temp->nxt;
        temp->nxt=ptr;
        ptr->prev=temp;
    }
}
//DELETION
void delHead(Node* &head){
    Node *ptr=head;
    head=head->nxt;
    head->prev=NULL;
    free(ptr);
}
void delIndex(Node* &head, int index){
    if(index==0)    delHead(head);
    else{
        Node *temp=head;
        int cnt=0;
        while(cnt!=index && temp!=NULL){
            temp=temp->nxt;
            cnt++;
        } temp->prev->nxt=temp->nxt;
        if(temp->nxt!=NULL)    temp->nxt->prev=temp->prev;
        free(temp);
    }
}
//REVERSE LINKED LIST
void reverse(Node* &head){
    if(head==NULL)   return;
    Node *previous=NULL, *curnt=head;
    while(curnt!=NULL){
        Node *next=curnt->nxt;
        curnt->nxt=previous;
        curnt->prev=next;
        previous=curnt;
        curnt=next;
    } head=previous;
}
int main() {
    int n=3,l;
    Node *head=NULL;
    // cout<<"Koyta dhukabi: ";
    // cin>>n;
    cout<<"Dhukaite thak\n";
    for(int i=0;i<n;i++){
        cin>>l;
        insertTail(head,l);
    } traverse(head);
    cout<<"Mathai dhuka\n";
    insertHead(head,69);
    reverse(head);
    traverse(head);
    
    return 0;
}
