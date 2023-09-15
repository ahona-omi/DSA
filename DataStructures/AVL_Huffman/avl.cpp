#include <bits/stdc++.h>
using namespace std;

template<typename T>
class AVLTreeNode {
public:
    T data;
    int height;
    AVLTreeNode<T>* left;
    AVLTreeNode<T>* right;
    AVLTreeNode(T value) {
        data = value;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};
template<typename T>
class AVLTree {
private:
    AVLTreeNode<T>* root;
    int height(AVLTreeNode<T>* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }
    int balanceFactor(AVLTreeNode<T>* node) {
        if (node == nullptr) {
            return 0;
        }
        return height(node->left) - height(node->right);
    }
    AVLTreeNode<T>* rightRotate(AVLTreeNode<T>* y) {
        AVLTreeNode<T>* x = y->left;
        AVLTreeNode<T>* z = x->right;

        x->right = y;
        y->left = z;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }
    AVLTreeNode<T>* leftRotate(AVLTreeNode<T>* x) {
        AVLTreeNode<T>* y = x->right;
        AVLTreeNode<T>* z = y->left;

        y->left = x;
        x->right = z;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    AVLTreeNode<T>* insert(AVLTreeNode<T>* node, T value) {
        if (node == nullptr) {
            return new AVLTreeNode<T>(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        node->height = max(height(node->left), height(node->right)) + 1;
        int bf = balanceFactor(node);
        if (bf > 1 && value < node->left->data) {
            return rightRotate(node);
        }
        if (bf < -1 && value > node->right->data) {
            return leftRotate(node);
        }
        if (bf > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (bf < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    AVLTreeNode<T>* deleteNode(AVLTreeNode<T>* node, T value) {
        if (node == nullptr) {
            return node;
        }
        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            if (node->left == nullptr || node->right == nullptr) {
                AVLTreeNode<T>* temp = node->left ? node->left : node->right;

                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                AVLTreeNode<T>* temp = node->right;

                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }
        if (node == nullptr) {
            return node;
        }
        node->height = max(height(node->left), height(node->right)) + 1;
        int bf = balanceFactor(node);
        if (bf > 1 && balanceFactor(node->left) >= 0) {
            return rightRotate(node);
        }
        if (bf > 1 && balanceFactor(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (bf < -1 && balanceFactor(node->right) <= 0) {
            return leftRotate(node);
        }
        if (bf < -1 && balanceFactor(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    void printInorder(AVLTreeNode<T>* node) {
        if (node == nullptr) {
            return;
        }
        printInorder(node->left);
        cout << node->data << " ";
        printInorder(node->right);
    }
public:
    AVLTree() {
        root = nullptr;
    }
    void insert(T value) {
        root = insert(root, value);
    }
    void print() {
        printInorder(root);
    }
};
int main() {
    AVLTree<int> tree;
    tree.insert(4);
    tree.insert(2);
    tree.insert(7);
    tree.insert(1);
    tree.insert(3);
    tree.insert(6);
    tree.insert(9);
    tree.print();
}