#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    char data;
    int freq;
    Node *left,*right;
    Node(char data, int freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};
class compare {
public:
    bool operator()(Node* l, Node* r) {
        return (l->freq > r->freq);
    }
};
void printCodes(Node* root, string str) {
    if (!root)    return;
    if (root->data != '-') {
        cout << root->data << ": " << str << endl;
    }
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}
void HuffmanCodes(char data[], int freq[], int size) {
    Node *left, *right, *tmp;
    priority_queue<Node*, vector<Node*>, compare> pq;

    for (int i = 0; i < size; i++) {
        pq.push(new Node(data[i], freq[i]));
    }
    while (pq.size() != 1) {
        left = pq.top();
        pq.pop();

        right = pq.top();
        pq.pop();

        tmp = new Node('-', left->freq + right->freq);
        tmp->left = left;
        tmp->right = right;

        pq.push(tmp);
    }
    printCodes(pq.top(), " ");
}

int main() {
    char arr[] = {'a','b','c','d','e'};
    int freq[] = {4,7,3,2,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    HuffmanCodes(arr,freq,size);
    return 0;
}
