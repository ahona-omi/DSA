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
    cout<<"Circular LinkedList: ";
    Node *ptr=head;
    do{
        cout<<ptr->data<<" ";
        ptr=ptr->nxt;
    } while(ptr!=head);
    cout<<endl;
}
//INSERTION
void insertHead(Node* &head, int x){
    Node *ptr=new Node(x);
    if(head==NULL){
        ptr->nxt=ptr;
        head=ptr;
    } else{
        Node *p=head;
        while(p->nxt!=head)     p=p->nxt;
        p->nxt=ptr;
        ptr->nxt=head;
        head=ptr;
    }
}
void insertTail(Node* &head, int x){
    if(head==NULL)     insertHead(head,x);
    else{
        Node *ptr=new Node(x), *p=head;
        while(p->nxt!=head)     p=p->nxt;
        p->nxt=ptr;
        ptr->nxt=head;
    }
}
//DELETION
void delHead(Node* &head){
    Node *temp=head, *ptr=head;
    while(temp->nxt!=head)     temp=temp->nxt;
    temp->nxt=head->nxt;
    head=head->nxt;
    free(ptr);
}
void delIndex(Node* &head, int index){
    if(index==0)    delHead(head);
    else{
        Node *temp=head;
        int cnt=0;
        while(cnt!=index-1){
            temp=temp->nxt;
            cnt++;
        } Node *ptr=temp->nxt;
        temp->nxt=temp->nxt->nxt;
        free(ptr);
    }
}

//REVERSE CIRCULAR LINKED-LIST
void reverse(Node* &head){
    if(head==NULL || head->nxt==head)   return;
    Node *prev=NULL, *curnt=head;
    do{
        Node *next=curnt->nxt;
        curnt->nxt=prev;
        prev=curnt;
        curnt=next;
    } while(curnt!=head);
    head->nxt=prev;
    head=prev;
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
    traverse(head);
    reverse(head);
    traverse(head);
    return 0;
}
