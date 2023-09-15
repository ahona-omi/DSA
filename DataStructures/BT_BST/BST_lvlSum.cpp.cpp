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
BinSTree* search(BinSTree* root, int x){
    if(root==NULL)     return NULL;
    if(x==root->data)    return root;
    if(root->data>x)    return search(root->lft,x);
    return search(root->rgt,x);
}
int sumAtK(BinSTree *root, int k){
    if(root==NULL)     return -1;
    queue<BinSTree*> q;
    q.push(root);
    q.push(NULL);
    int lvl=0, sum=0;
    while(!q.empty()){
        BinSTree* node=q.front();
        q.pop();
        if(node !=NULL){
            if(lvl==k)     sum+=node->data;
            if(node->lft)   q.push(node->lft);
            if(node->rgt)   q.push(node->rgt);
        } else if(!q.empty()){
            q.push(NULL);
            lvl++;
        }
    }
    return sum;
}
void inOrder(BinSTree *root){
    if(root==NULL)     return;
    inOrder(root->lft);
    cout<<root->data<<" ";
    inOrder(root->rgt);
}
void levelOrder(BinSTree *root){
    if(root==NULL)     return;
    queue<BinSTree*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        BinSTree* node=q.front();
        q.pop();
        if(node !=NULL){
            cout<<node->data<<" ";
            if(node->lft)   q.push(node->lft);
            if(node->rgt)   q.push(node->rgt);
        } else if(!q.empty())   q.push(NULL);
    }
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
    cout<<"Level traverse: ";
    levelOrder(root);
    cout<<"\nSum: "<<sumAtK(root,1)<<endl;
    return 0;
}