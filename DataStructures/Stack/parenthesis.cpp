#include <bits/stdc++.h>
using namespace std;
const int N=INT_MAX;
class Stack{
    int top, cnt;
    char *arr;
public:
    Stack(){
        top=-1;
        cnt=0;
        arr= new char[N];
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
    void push(char x) {
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
};
bool paren(string eq){
    Stack *s=new Stack();
    char x;
    for(int i=0;i<eq.length();i++){
        if(eq[i]=='(' || eq[i]=='{' || eq[i]=='['){
            s->push(eq[i]);
            continue;
        } if(s->isEmpty())  return false;
        switch(eq[i]){
            case ')':
                x=s->Top();
                s->pop();
                if(x=='{' || x=='[')    return false;
                break;
            case '}':
                x=s->Top();
                s->pop();
                if(x=='(' || x=='[')    return false;
                break;
            case ']':
                x=s->Top();
                s->pop();
                if(x=='{' || x=='(')    return false;
                break;
        }
    } return s->isEmpty();
}
int main() {
    string s="{[()]}";
    cout<<paren(s)<<endl;
    return 0;
}
