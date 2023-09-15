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
int Search(int inO[], int strt, int end, int cur){
    for(int i=0;i<=end;i++){
        if(cur==inO[i])   return i;
    } return -1;
}
BinTree* buileTre(int preO[], int inO[], int strt, int end){
    static int idx=0;
    if(strt>end)    return NULL;
    int cur= preO[idx];
    idx++;
    BinTree* node= new BinTree(cur);
    if(strt==end)   return node;
    int pos= Search(inO, strt, end, cur);
    node->lft= buileTre(preO, inO, strt, pos-1);
    node->rgt= buileTre(preO, inO, pos+1, end);
    return node;
}
void inOrder(BinTree *root){
    if(root==NULL)     return;
    inOrder(root->lft);
    cout<<root->data<<" ";
    inOrder(root->rgt);
}

int main(){
    int n=4;
    int preO[]={1,2,4,3,5};
    int inO[]= {4,2,1,5,3};
    BinTree* root= buileTre(preO, inO, 0, n);
    cout<<"Inorder traverse: ";
    inOrder(root);
    return 0;
}