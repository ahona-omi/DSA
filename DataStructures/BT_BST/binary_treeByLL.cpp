#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

//______________insertion_____________________________
Node* insertBST(Node *root, int val){
    if(root == NULL){
        return new Node(val);
    }

    if(val < root->data){
        root->left = insertBST(root->left,val);
    }
    else{
        root->right = insertBST(root->right,val);
    }

    return root;
}

//_________________Deletion__________________
Node* inorderSucc(Node* root){
    Node* curr = root;
    while(curr && curr->left != NULL){
        curr = curr->left;
    }
        return curr;
}

Node* deleteInBST(Node *root, int key){
    if(key < root->data){
        root->left = deleteInBST(root->left,key);
    }
    else if(key > root->data){
        root->right = deleteInBST(root->right,key);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = inorderSucc(root->right);

        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
        return root;
}

//___________________Search_____________________
Node* searchInBST(Node *root, int key){
    if(root == NULL){
        return NULL;
    }
    else if(root->data == key){
        return root;
    }
    else if(root->data > key){
        return searchInBST(root->left,key);
    }
    else{
        return searchInBST(root->right, key);
    }
}

//___________________Traverse tree__________________
    void preorder(Node* root){
        if(root == NULL){
            return;
        }
        cout<< root->data <<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(Node* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

void inorderStack(Node* root) {
    stack<Node*> nodeStack;
    Node* current = root;

    while (current != nullptr || !nodeStack.empty()) {
        // Traverse down the left side of the tree, pushing nodes onto the stack
        while (current != nullptr) {
            nodeStack.push(current);
            current = current->left;
        }

        // Pop a node from the stack and visit it
        current = nodeStack.top();
        nodeStack.pop();
        
        cout << current->data << " "; // Process the node (e.g., print its value)

        // Move to the right subtree
        current = current->right;
    }
}

    void postorder(Node* root){
        if(root == NULL){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data <<" ";

    }

//_______________height________________________
    int height(Node* root){
        if(root == NULL){
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        return max(lh,rh) + 1;
    }

//_________________Perfect BST???_________________
    bool isPerfect(Node* root){
        if(root==NULL){return true;}
        if(isPerfect(root->left)==false){return false;}
        if(isPerfect(root->right)==false){return false;}

        int lh=height(root->left);
        int rh=height(root->right);
        if((lh-rh)==0){
            return true;
        }
        else{
            return false;
        }
    }

//____________Full BST???__________________
    bool isFull(Node* root){
        if(root==NULL){return true;}
        if(isFull(root->left)==false){return false;}
        if(isFull(root->right)==false){return false;}

        //l,r both null
        if((root->left==NULL)&&(root->right==NULL)){
            return true;
        }
        //l,r both not null
        if((root->left!=NULL)&&(root->right!=NULL)){
            return true;
        }
        // l/r one is null  another is not
        else{
            return false;
        }
    }


//_________________Complete BST???__________________
    bool isComplete(Node* root){
        if(root==NULL){return true;}
        if(isComplete(root->left)==false){return false;}
        if(isComplete(root->right)==false){return false;}

        int lh=height(root->left);
        int rh=height(root->right);
        if((lh-rh)>=0){ //lh>rh
            return true;
        }
        else{
            return false;
        }
    }


//______________Balanced BST by height???_______________
    bool isBalanced(Node* root){
        if(root==NULL){return true;}
        if(isBalanced(root->left)==false){return false;}
        if(isBalanced(root->right)==false){return false;}

        int lh=height(root->left);
        int rh=height(root->right);
        if(abs(lh-rh)<=1){
            return true;
        }
        else{
            return false;
        }
    }



//______________left skewed tree ??_________________
    bool isLeftSkewed(Node* root){
        if(root==NULL){return true;}
        if(root->right!=NULL){return false;}
        //root=root->left;
        return isLeftSkewed(root->left);

    }

//_______________right skewed tree ??__________________
    bool isRightSkewed(Node* root){
        if(root==NULL){return true;}
        if(root->left!=NULL){return false;}
        //root=root->left;
        return isRightSkewed(root->right);
    }

//__________________degenerate??______________________
    bool isDegenerate(Node* root){
        if(isLeftSkewed(root) || isRightSkewed(root) ){
            return true;
        }
        else {
            return false;
        }
    }
int kthSmallestElement(Node* root, int k) {
    stack<Node*> nodeStack;
    Node* current = root;
    int count = 0;
    int kthSmallest = -1;

    while (current != nullptr || !nodeStack.empty()) {
        // Traverse down the left side of the tree, pushing nodes onto the stack
        while (current != nullptr) {
            nodeStack.push(current);
            current = current->left;   //largest->right
        }

        // Pop a node from the stack and visit it
        current = nodeStack.top();
        nodeStack.pop();

        // Increment the count and check if it matches k
        count++;
        if (count == k) {
            kthSmallest = current->data;
            break;
        }

        // Move to the right subtree
        current = current->right;        //largest->left
    }

    return kthSmallest;
}

int main(){

    Node *root = NULL;
    root = insertBST(root,69);
    insertBST(root,0);
    insertBST(root,420);
    insertBST(root,-2);
    insertBST(root,1);
    insertBST(root,-3);
    insertBST(root,13);

    cout<<"Inorder :";
    inorder(root);
    cout<<endl;

    cout<<"Inorder :";
    inorderStack(root);
    cout<<endl;

    cout<<"Preorder :";
    preorder(root);
    cout<<endl;

    cout<<"Postorder :";
    postorder(root);
    cout<<endl;
    cout<<endl;  

        //Perfect BST
    if (isPerfect(root)) {
        cout << "Perfect " << "\n";
    } else {
        cout << "Not Perfect" << "\n";
    }

    //Full BST
    if (isFull(root)) {
        cout << "Full " << "\n";
    } else {
        cout << "Not Full" << "\n";
    }

    //Complete BST
    if (isComplete(root)) {
        cout << "Complete " << "\n";
    } else {
        cout << "Not Complete" << "\n";
    }


    //Balanced by height
    if (isBalanced(root)) {
        cout << "Balanced " << "\n";
    } else {
        cout << "Not Balanced" << "\n";
    }


    //Degenerate
    if (isDegenerate(root)) {
        cout << "Degenerate " << "\n";
    } else {
        cout << "Not Degenerate" << "\n";
    }


    //left skewed
    if (isLeftSkewed(root)) {
        cout << "Left skewed " << "\n";
    } else {
        cout << "Not Left skewed" << "\n";
    }

    //right skewed
    if (isRightSkewed(root)) {
        cout << "Right skewed " << "\n";
    } else {
        cout << "Not Right skewed" << "\n";
    }
    int k = 7;
    int kthSmallest = kthSmallestElement(root, k);

    cout << "\nThe kth smallest element is: " << kthSmallest << endl;

    return 0;
}