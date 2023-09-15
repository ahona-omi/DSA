/*merging a 2D array of integers 
into a sorted linked list*/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* nxt;
    Node(int val){
        data=val;
        nxt=NULL;
    }
};
void insertAtTail(Node* &head, int val){
    Node* n = new Node(val);
    if(head==NULL)    head=n;
    else {
        Node* temp=head;
        while(temp->nxt!=NULL)    temp=temp->nxt;
        temp->nxt=n;
    }
}
Node* merge(Node* &head1,Node* &head2){
    Node *p1=head1, *p2=head2;
    Node* dummynode=new Node(0);
    Node* p3=dummynode;
    while(p1!=NULL && p2!=NULL){
        if(p1->data < p2->data){
            p3->nxt=p1;
            p1=p1->nxt;
        } else{
            p3->nxt=p2;
            p2=p2->nxt;
        } p3=p3->nxt;
    }
    while(p1!=NULL){
        p3->nxt=p1;
        p1=p1->nxt;
        p3=p3->nxt;
    }
    while(p2!=NULL){
        p3->nxt=p2;
        p2=p2->nxt;
        p3=p3->nxt;
    } return dummynode->nxt;
}
void traverse(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->nxt;
    } cout<<"NULL"<<endl;
}

int main(){
    int n=3;
    Node *head=NULL, *temp=NULL, *merged=NULL;
    int arr[n][n]={{1,4,5},{1,3,4},{2,6,0}};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==n-1 && j==n-1 && arr[i][j]==0)    break;
            insertAtTail(temp,arr[i][j]);
        } 
        merged=merge(head,temp);
        head=merged;
        temp=NULL;
        merged=NULL;
    } traverse(head);
    return 0;
}