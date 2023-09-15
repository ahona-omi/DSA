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
int calH(BinSTree *root){ //O(n)
    if(root==NULL)     return 0;
    return max(calH(root->lft),calH(root->rgt))+1;
}
int calDiaM(BinSTree *root){ //O(n^2)
    if(root==NULL)     return 0;
    int lH= calH(root->lft);
    int rH= calH(root->rgt);
    int curDm= lH+rH+1;
    int lD= calDiaM(root->lft);
    int rD= calDiaM(root->rgt);
    return max(curDm,max(lH,rH));
}
int calDiaM1(BinSTree *root, int* h){ //O(n)
    if(root==NULL){
        *h=0;
        return 0;
    }
    int lH= 0,rH= 0;
    int lD= calDiaM1(root->lft, &lH);
    int rD= calDiaM1(root->rgt, &rH);
    int curDm= lH+rH+1;
    *h= max(lH,rH)+1;
    return max(curDm,max(lD,rD));
}
void inOrder(BinSTree *root){
    if(root==NULL)     return;
    inOrder(root->lft);
    cout<<root->data<<" ";
    inOrder(root->rgt);
}

int main(){
    BinSTree* root= new BinSTree(1);
    root = insert(root, 1);
    root->lft= new BinSTree(2);
    root->rgt= new BinSTree(3);
    root->lft->lft= new BinSTree(4);
    root->lft->rgt= new BinSTree(5);
    root->rgt->lft= new BinSTree(6);
    root->rgt->rgt= new BinSTree(7);
    cout<<"Traverse: ";
    inOrder(root);
    cout<<"\nHeight: "<<calH(root)<<endl;
    cout<<"Diameter: "<<calDiaM(root)<<endl;
    int hgt=0;
    cout<<"Diameter1: "<<calDiaM1(root, &hgt)<<endl;
    return 0;
}