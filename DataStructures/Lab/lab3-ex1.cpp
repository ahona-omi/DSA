/*merging of two sorted linked lists
into a single sorted linked list*/

#include<bits/stdc++.h>

using namespace std;
const int N=1e9+7;
typedef long long int ll;

class Node{
public:
    int data;
    Node* nxt;
    Node(int x){
        data=x;
        nxt=NULL;
    }
};
void insertAtTail(Node* &head, int x){
    Node* n = new Node(x);
    if(head==NULL)    head=n;
    else{
        Node* temp=head;
        while(temp->nxt!=NULL)    temp=temp->nxt;
        temp->nxt=n;
    }
}
Node* merge(Node* &head1,Node* &head2){
    Node *p1=head1, *p2=head2;
    Node* dummynode=new Node(0);
    Node *p3=dummynode;
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
    Node* hd1=NULL;
    Node* hd2=NULL;
    int arr1[]={1,2,4};
    int arr2[]={1,3,4};
    for(int i=0;i<(sizeof(arr1)/sizeof(arr1[0]));i++){
        insertAtTail(hd1,arr1[i]);
    }
    for(int i=0;i<(sizeof(arr2)/sizeof(arr2[0]));i++){
        insertAtTail(hd2,arr2[i]);
    } cout<<"Head-1: ";
    traverse(hd1);
    cout<<"Head-2: ";
    traverse(hd2);
    Node* mrgdhd=merge(hd1,hd2);
    cout<<"Merge : ";
    traverse(mrgdhd);
    return 0;
}