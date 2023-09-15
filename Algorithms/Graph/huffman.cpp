#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    int weight;
    Node* left;
    Node* right;

    Node(char d, int w) {
        data = d;
        weight = w;
        left = nullptr;
        right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->weight > b->weight;
    }
};

Node* constructHuffmanTree(char data[], int weight[], int n) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < n; i++) {
        Node* newNode = new Node(data[i], weight[i]);
        pq.push(newNode);
    }

    // Merge trees until only one tree remains
    while (pq.size() > 1) {
        Node* first = pq.top();
        pq.pop();

        Node* second = pq.top();
        pq.pop();

        // Create a new node as the parent of the merged trees
        Node* parent = new Node('$', first->weight + second->weight);
        parent->left = first;
        parent->right = second;

        pq.push(parent);
    }

    return pq.top();
}

void printHuffmanCodes(Node* root, string code) {
    if (root == nullptr)    return;

    // Leaf node
    if (!root->left && !root->right)
        cout << root->data << ": " << code << endl;

    printHuffmanCodes(root->left, code + "0");
    printHuffmanCodes(root->right, code + "1");
}

int main() {
    int n;
    cin >> n;
    char data[n];
    int weight[n];
    for(int i = 0; i < n; i++){
        cin>>data[i]>>weight[i];
    }
    Node* root = constructHuffmanTree(data, weight, n);

    //cout << "Huffman Codes:" << endl;
    printHuffmanCodes(root, "");

    return 0;
}
