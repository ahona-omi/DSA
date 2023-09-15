#include <iostream>
#include <vector>
using namespace std;

// Node structure for binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to calculate the size of each subtree
int calculateSize(Node* root, vector<int>& sizes) {
    if (root == nullptr)
        return 0;

    int leftSize = calculateSize(root->left, sizes);
    int rightSize = calculateSize(root->right, sizes);
    int totalSize = leftSize + rightSize + 1;

    sizes[root->data] = totalSize; // Store the size for each node

    return totalSize;
}

// Function to find the center of the binary tree
int findCenter(Node* root, vector<int>& sizes, int totalSize) {
    if (root == nullptr)
        return -1;

    int leftSize = root->left ? sizes[root->left->data] : 0; // Size of the left subtree
    int rightSize = root->right ? sizes[root->right->data] : 0; // Size of the right subtree

    if (leftSize == totalSize / 2 || rightSize == totalSize / 2 || totalSize - leftSize - rightSize - 1 == totalSize / 2)
        return root->data; // Found the center node

    if (leftSize > rightSize)
        return findCenter(root->left, sizes, totalSize);
    else
        return findCenter(root->right, sizes, totalSize);
}

// Function to find the center of the binary tree
int findCenterOfTree(Node* root) {
    if (root == nullptr)
        return -1;

    vector<int> sizes(1000, 0); // Vector to store the size of each node's subtree
    int totalSize = calculateSize(root, sizes);

    return findCenter(root, sizes, totalSize);
}

int main() {
    Node* root = new Node(69);
    root->left = new Node(2);
    root->right = new Node(3);
    //root->left->left = new Node(4);
    root->left->right = new Node(1);
    //root->right->left = new Node(6);
    root->right->right = new Node(7);

    int center = findCenterOfTree(root);
    cout << "Center of the tree: " << center << endl;

    return 0;
}
