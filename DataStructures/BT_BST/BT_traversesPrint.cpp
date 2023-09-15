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
void preorder(Node *root){
    if(root==NULL)  {return;}

    cout<<root->data<<" ";
    preorder(root->lft);
    preorder(root->rgt);
}
void postorder(Node *root){
    if(root==NULL)  {return;}

    postorder(root->lft);
    postorder(root->rgt);
    cout<<root->data<<" ";
}
void inorder(Node *root){
    if(root==NULL)  {return;}

    inorder(root->lft);
    cout<<root->data<<" ";
    inorder(root->rgt);
}
void buildrows(Node* root,vector < vector<pair<int, unsigned> > >& rows,unsigned & pos, unsigned level) {
    if (root == nullptr) return;
    if (level >= rows.size())   // need to add a new row
        rows.push_back(vector<pair<int, unsigned> >());
    buildrows(root->lft, rows, pos, level + 1);
    pair<int, unsigned> p{ root->data, pos++ }; // here is pos handling
    rows[level].push_back(p);
    buildrows(root->rgt, rows, pos, level + 1);
}
/* root is the tree to print, width is the width used to print a value */
void printTree(Node* root, size_t width) {
    vector < vector<pair<int, unsigned> > > rows;
    unsigned pos = 0;   // the position in the tree
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
/* Get width of a given level */
int getWidth(Node* root, int level){
    if (root == NULL)    return 0;
    if (level == 1)    return 1;
    else if (level > 1)
        return (getWidth(root->lft, level - 1) + getWidth(root->rgt, level - 1));
    else    return 0;
}
/* UTILITY FUNCTIONS */
/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(Node* node){
    if (node == NULL)    return 0;
    else {
        /* compute the height of each subtree */
        int lHeight = height(node->lft);
        int rHeight = height(node->rgt);
        /* use the larger one */
        return (lHeight > rHeight) ? (lHeight + 1) : (rHeight + 1);
    }
}

int getMaxWidth(Node* root){
    int maxWidth = 0;
    int width;
    int h = height(root);
    int i;
    /* Get width of each level and compare
        the width with maximum width so far */
    for (i = 1; i <= h; i++) {
        width = getWidth(root, i);
        if (width > maxWidth)    maxWidth = width;
    } return maxWidth;
}

int main(){
    Node *root=new Node(1);
    root->lft=new Node(2);
    root->rgt=new Node(3);
    root->lft->lft=new Node(4);
    root->lft->rgt=new Node(5);
    root->rgt->lft=new Node(6);
    root->rgt->rgt=new Node(7);
    root->lft->lft->lft=new Node(8);
    root->lft->lft->rgt=new Node(9);
    root->rgt->rgt->lft=new Node(10);
    root->rgt->rgt->rgt=new Node(11);
    root->rgt->rgt->lft->lft=new Node(12);
    root->rgt->rgt->rgt->rgt=new Node(13);
    int x=getMaxWidth(root);
    printTree(root,x);
    return 0;
}