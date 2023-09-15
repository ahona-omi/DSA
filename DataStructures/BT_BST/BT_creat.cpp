#include<bits/stdc++.h>

using namespace std;
const int N=1e9+7;
typedef long long int ll;
class Node{
public:
    int data;
    Node *lft, *rgt;
    Node(int val){
        data=val;
        lft=rgt=NULL;
    }
};

void buildrows(Node* root,vector < vector<pair<int, unsigned> > >& rows,unsigned & pos, unsigned level) {
    if (root == nullptr) return;
    if (level >= rows.size())
        rows.push_back(vector<pair<int, unsigned> >());
    buildrows(root->lft, rows, pos, level + 1);
    pair<int, unsigned> p{ root->data, pos++ };
    rows[level].push_back(p);
    buildrows(root->rgt, rows, pos, level + 1);
}
void printTree(Node* root, size_t width) {
    vector < vector<pair<int, unsigned> > > rows;
    unsigned pos = 0;
    buildrows(root, rows, pos, 0);
    for (auto& row : rows) {
        pos = 0;
        for (auto& it : row) {
            unsigned delta = 1 + it.second - pos;
            cout << setw(delta * width) << it.first ;
            pos = it.second + 1;
        } cout << endl;
    }
}
int getWidth(Node* root, int level){
    if (root == NULL)    return 0;
    if (level == 1)    return 1;
    else if (level > 1)
        return (getWidth(root->lft, level - 1) + getWidth(root->rgt, level - 1));
    else    return 0;
}
int height(Node* node){
    if (node == NULL)    return 0;
    else {
        int lHeight = height(node->lft);
        int rHeight = height(node->rgt);
        return (lHeight > rHeight) ? (lHeight + 1) : (rHeight + 1);
    }
}
int getMaxWidth(Node* root){
    int maxWidth = 0, width,h = height(root);
    for (int i = 1; i <= h; i++) {
        width = getWidth(root, i);
        if (width > maxWidth)    maxWidth = width;
    } return maxWidth;
}
int search(int inorder[], int inSt, int inEnd, int curr){
    for(int i = 0; i<=inEnd;i++) {
        if(inorder[i] == curr)     return i;
    } return -1;
}
Node* buildTree(int preorder[], int inorder[], int inSt, int inEnd){
    if(inSt > inEnd)    return NULL;
    static int pInx=0;
    int curr=preorder[pInx++];
    Node* node= new Node(curr);
    if(inSt == inEnd)   return node;
    int pos= search(inorder,inSt, inEnd,curr);
    node->lft= buildTree(preorder,inorder, inSt,pos-1);
    node->rgt= buildTree(preorder,inorder,pos+1, inEnd);
    return node;
}
int main(){
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    Node *root= buildTree(preorder,inorder,0,4);
    cout<<endl;
    int x=getMaxWidth(root);
    printTree(root,x);
    return 0;
}