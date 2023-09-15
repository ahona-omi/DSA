#include<bits/stdc++.h>
using namespace std;

class BinTree{
public:
    int data;
    BinTree *lft, *rgt;
    BinTree(int x){
        data = x;
        lft =rgt= NULL;
    } ~BinTree();
};
void preOrder(BinTree *root){
    if(root==NULL)     return;
    cout<<root->data<<" ";
    preOrder(root->lft);
    preOrder(root->rgt);
}
void postOrder(BinTree *root){
    if(root==NULL)     return;
    postOrder(root->lft);
    postOrder(root->rgt);
    cout<<root->data<<" ";
}
void inOrder(BinTree *root){
    if(root==NULL)     return;
    inOrder(root->lft);
    cout<<root->data<<" ";
    inOrder(root->rgt);
}
int main(){
    // int n=6,y,k,sum=0,i=0,j=0,tSum=0,Min=INT_MAX;
    // cout<<"Enter k-> ";
    // cin>>k;
    BinTree *root= new BinTree(1);
    root->lft= new BinTree(2);
    root->rgt= new BinTree(3);
    root->lft->lft= new BinTree(4);
    root->lft->rgt= new BinTree(5);
    root->rgt->lft= new BinTree(6);
    root->rgt->rgt= new BinTree(7);
    // cout<<"Preorder traverse: ";
    // preOrder(root);
    // cout<<"Inorder traverse: ";
    // inOrder(root);
    cout<<"Postorder traverse: ";
    postOrder(root);
    return 0;
}