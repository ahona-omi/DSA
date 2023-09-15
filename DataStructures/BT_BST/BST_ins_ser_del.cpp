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

Node* insert(Node* root, int val){
    if (root == NULL)    return new Node(val);
    if (val < root->data)    root->lft = insert(root->lft, val);
    else    root->rgt = insert(root->rgt, val);
    return root;
}
Node *search(Node* root, int key){
    if (root == NULL)    return NULL;
    if(root->data== key)    return root;
    if (key < root->data)    return search(root->lft, key);
    return search(root->rgt, key);
}
Node *inorderSuc(Node *root){
    Node *temp = root;
    while (temp && temp->lft!= NULL)    temp = temp->lft;
    return temp;
}
Node *Delete(Node* root, int key){
    if(key < root->data)
        root->lft = Delete(root->lft, key);
    else if(key>root->data)
        root->rgt = Delete(root->rgt, key);
    else{
        if(root->lft==NULL){
            Node *temp= root->rgt;
            free(root);
            return temp;
        } else if(root->rgt==NULL){
            Node *temp= root->lft;
            free(root);
            return temp;
        } else{
            Node *temp= inorderSuc(root->rgt);
            root->data= temp->data;
            root->rgt= Delete(root->rgt, temp->data);
        }
    } return root;
}

int main(){
    Node *root= new Node(4);
    insert(root, 2);
    insert(root, 5);
    insert(root, 1);
    insert(root, 3);
    insert(root, 6);
    int l=getMaxWidth(root);
    printTree(root,l);
    cout<<endl<<"Delete"<<endl;
    root= Delete(root,4);
    int l1=getMaxWidth(root);
    printTree(root,l1);
    return 0;
}