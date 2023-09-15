#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* nxt;
    Node(int x) {
        data = x;
        nxt = NULL;
    }
};
class Stack {
private:
    Node* top;
public:
    Stack()     {top = NULL;}
    void push(int x) {
        Node* newN = new Node(x);
        if (top == NULL)    top = newN;
        else {
            newN->nxt = top;
            top = newN;
        }
    }
    void pop() {
        if (top == NULL)    cout << "Stack is empty\n";
        else {
            Node* temp = top;
            top = top->nxt;
            delete temp;
        }
    }
    int peek() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return -1;
        } return top->data;
    }
    bool isEmpty()   {return top == NULL;}
    void display() {
        if (top == NULL)    cout << "Stack is empty\n";
        else {
            Node* temp = top;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->nxt;
            } cout<< endl;
        }
    }
    void reverse(){
        Node *curr = top, *prev = NULL, *next = NULL;
        while (curr != NULL) {
            next = curr->nxt;
            curr->nxt = prev;
            prev = curr;
            curr = next;
        } top = prev;
    }
};

int main() {
    Stack *st=new Stack();
    int l;
    for(int i=0;i<3;i++){
        cin>>l;
        st->push(l);
    } 
    cout<<st->peek()<<endl;
    st->display();
    st->pop();
    st->pop();
    st->display();
    st->push(69);
    st->push(420);
    st->display();
    return 0;
}
