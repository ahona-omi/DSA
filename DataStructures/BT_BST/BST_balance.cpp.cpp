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
int calH(BinSTree *root){ //O(n)
    if(root==NULL)     return 0;
    return max(calH(root->lft),calH(root->rgt))+1;
}
bool isBalanced(BinSTree* root){ //O(n^2)
    if(root==NULL)     return 1;
    if((isBalanced(root->lft)==0) || (isBalanced(root->rgt)==0))    return 0;
    int lH=calH(root->lft);
    int rH=calH(root->rgt);
    if(abs(lH-rH)<=1)   return 1;
    else    return 0;
}
bool Balanced(BinSTree* root, int* h){ //O(n)
    if(root==NULL)     return 1;
    int lH=0,rH=0;
    if((Balanced(root->lft, &lH)==0) || (Balanced(root->rgt, &rH)==0))    return 0;
    *h=max(lH,rH)+1;
    if(abs(lH-rH)<=1)   return 1;
    else    return 0;
}

int main(){
    BinSTree* root= new BinSTree(1);
    root->lft= new BinSTree(2);
    root->lft->lft= new BinSTree(4);
    cout<<"Traverse: ";
    inOrder(root);
    cout<<"\nBalanced kina bol : "<<isBalanced(root)<<endl;
    int hgt=0;
    cout<<"\nBalanced kina bol2: "<<Balanced(root, &hgt)<<endl;
    return 0;
}