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
BinSTree* inOrderSuc(BinSTree *root){
    BinSTree* curr= root;
    while(curr && curr->lft != NULL)    curr=curr->lft;
    return curr;
}
BinSTree* Delete(BinSTree* root, int x){
    if(x<root->data)    root->lft=Delete(root->lft,x);
    else if(x>root->data)    root->rgt=Delete(root->rgt,x);
    else{
        if(root->lft==NULL){
            BinSTree* temp=root->rgt;
            free(root);
            return temp;
        } else if(root->rgt==NULL){
            BinSTree* temp=root->lft;
            free(root);
            return temp;
        }
            BinSTree* temp = inOrderSuc(root->rgt);
            root->data=temp->data;
            root->rgt= Delete(root->rgt, temp->data);
            
    } return root;
}
void inOrder(BinSTree *root){
    if(root==NULL)     return;
    inOrder(root->lft);
    cout<<root->data<<" ";
    inOrder(root->rgt);
}

int main(){
    BinSTree* root= NULL;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 5);
    insert(root, 1);
    insert(root, 3);
    insert(root, 6);
    cout<<"Inorder traverse: ";
    inOrder(root);
    root= Delete(root,5);
    cout<<"\nDelete traverse: ";
    inOrder(root);
    return 0;
}