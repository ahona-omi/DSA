#include <iostream>
using namespace std;

// Node structure for BST
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

// Function to create a balanced BST from a sorted array
Node* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end)
        return nullptr;

    // Find the middle element of the array
    int mid = (start + end) / 2;

    // Create a new node with the middle element as the data
    Node* root = new Node(arr[mid]);

    // Recursively construct the left and right subtrees
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

// Function to perform in-order traversal of BST
void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create a balanced BST from the sorted array
    Node* root = sortedArrayToBST(arr, 0, n - 1);

    // Perform in-order traversal to verify the BST
    cout << "In-order traversal of the BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
