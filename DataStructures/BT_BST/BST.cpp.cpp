#include<bits/stdc++.h>
using namespace std;

class BinSTree{
public:
    int data;
    BinSTree *lft, *rgt;
    BinSTree(int x){
        data = x;
        lft =rgt= NULL;
    } ~BinSTree();
};
BinSTree* insert(BinSTree* root, int x){
    if(root==NULL)     return new BinSTree(x);
    if(x<root->data)    root->lft=(insert(root->lft,x));
    else    root->rgt=(insert(root->rgt,x));
    return root;
}
void inOrder(BinSTree *root){
    if(root==NULL)     return;
    inOrder(root->lft);
    cout<<root->data<<" ";
    inOrder(root->rgt);
}

int main(){
    int n=4;
    int preO[]={1,2,4,3,5};
    int inO[]= {4,2,1,5,3};
    BinSTree* root= NULL;
    root = insert(root, 5);
    insert(root, 1);
    insert(root, 3);
    insert(root, 4);
    insert(root, 2);
    insert(root, 7);
    cout<<"Inorder traverse: ";
    inOrder(root);
    return 0;
}