#include <bits/stdc++.h>
using namespace std;

class Stack{
    int top, size, *arr;
public:
    Stack(int n){
        size = n;
        top = -1;
        arr = new int[n];
    }
    bool isEmpty(Stack *ptr) { return ptr->top == -1; }
    bool isFull(Stack *ptr) { return ptr->top == ptr->size - 1; }
    void push(Stack *ptr, int x){
        if (isFull(ptr))    cout << "Overflow!\n";
        else{
            ptr->top++;
            ptr->arr[ptr->top] = x;
        }
    }
    int pop(Stack *ptr){
        int x=-1;
        if (isEmpty(ptr))    cout << "!Element\n";
        else{
            x = ptr->arr[ptr->top];
            ptr->top--;
        } return x;
    }
    int Top(Stack *ptr) { return ptr->arr[ptr->top]; }
};
void insertBottom(Stack *st, int ele){
    if(st->isEmpty(st)){
        st->push(st,ele);
        return;
    }
    int topEle = st->Top(st);
    st->pop(st);
    insertBottom(st,ele);
    st->push(st,topEle);
}
void reverse(Stack *st){
    if(st->isEmpty(st))    return;
    int ele = st->Top(st);
    st->pop(st);
    reverse(st);
    insertBottom(st,ele);
    while (!st->isEmpty(st)){
        cout << st->Top(st) << " ";
        st->pop(st);
    }
}
int main(){
    int x;
    Stack *s = new Stack(5);
    for(int i=0;i<5;i++){
        cin>>x;
        s->push(s,x);
    }
    reverse(s);
    // while(!s->isEmpty(s)){
    //     cout<<s->Top(s)<<" ";
    //     s->pop(s);
    // } cout<<endl;
    return 0;
}