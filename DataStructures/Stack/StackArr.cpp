#include <bits/stdc++.h>
using namespace std;
const int N=INT_MAX;
class Stack{
    int top, cnt, *arr;
public:
    Stack(){
        top=-1;
        cnt=0;
        arr= new int[N];
    }
    int Size()  {return cnt;}
    bool isEmpty()  {return top==-1;}
    bool isFull()  {return top==N-1;}
    int Top(){
        if(isEmpty()){
            cout<<"!Element\n";
            return -1;
        } return arr[top];
    }
    int peek(int i){
        if (isEmpty() || i>=N){
            cout << "Queue is empty" << endl;
            return -1;
        } return arr[i];
    }
    void push(int x) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        } arr[++top] = x;
        cnt++;
    }
    void pop() {
        if (isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        } top--;
        cnt--;
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        } cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)    cout << arr[i] << " ";
        cout << endl;
    }
    void reverse(){
        int cpct=Size();
        int* temp = new int[cpct];
        for (int i = top; i >= 0; i--) {
            temp[top - i] = arr[i];
        } delete[] arr;
        arr = temp;
    }
};

int main() {
    Stack *st=new Stack();
    int l;
    for(int i=0;i<5;i++){
        cin>>l;
        st->push(l);
    } st->display();
    cout<<"Size "<<st->Size()<<endl;
    st->reverse();
    st->display();
    return 0;
}
