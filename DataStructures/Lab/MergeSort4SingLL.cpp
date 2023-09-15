/*Merge Sort algorithm for a singly linked list*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to merge two sorted linked lists
Node* merge(Node* head1, Node* head2) {
    Node* dummyNode = new Node(0);
    Node* tail = dummyNode;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    if (head1 != nullptr) {
        tail->next = head1;
    }

    if (head2 != nullptr) {
        tail->next = head2;
    }

    return dummyNode->next;
}

// Function to find the middle node of a linked list
Node* findMiddle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Merge Sort for linked list
Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* middle = findMiddle(head);
    Node* nextToMiddle = middle->next;
    middle->next = nullptr;

    Node* left = mergeSort(head);
    Node* right = mergeSort(nextToMiddle);

    return merge(left, right);
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n;
    cout << "Enter the number of elements in the linked list: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertAtEnd(head, val);
    }

    cout << "Original Linked List: ";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted Linked List: ";
    printList(head);

    return 0;
}
