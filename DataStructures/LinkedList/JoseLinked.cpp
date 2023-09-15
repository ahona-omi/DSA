#include <bits/stdc++.h>
using namespace std;


class Node{
public:
    int data;
    Node *nxt;
};
void insert(Node *&head,int n){
    head->data=1;
    Node *ptr=head;
    for(int i=2;i<=n;i++){
        Node *newN=new Node();
        ptr->nxt=newN;
        newN->data=i;
        newN->nxt=head;
        ptr=newN;
    }
}
void traverse(Node *head){
    Node *ptr= head;
    do{
        cout<<ptr->data<<" ";
        ptr=ptr->nxt;
    } while(ptr!=head);
    cout<<endl;
}
int jose(Node *head, int k){
    Node *p=head, *q=head;
    while (p->nxt != p){
        for (int i = 0; i < k - 1; i++){
            q = p;
            p = p->nxt;
        } q->nxt = p->nxt;
        printf("%d has been killed.\n", p->data);
        free(p);
        p = q->nxt;
    } head= p;
    return (p->data);
}

int main() {
    Node *head;
    int n=14,k=2;
    //cin>>n>>k;
    insert(head,n);
    //traverse(head);
    cout<<jose(head,k)<<endl;
    return 0;
}