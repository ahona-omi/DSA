#include<bits/stdc++.h>
using namespace std;

class Stack{
    int top,size;
    string *arr;
public:
    Stack(int n){
        size=n;
        top=-1;
        arr=new string[n];
    }
    bool isEmpty(Stack* ptr)    {return ptr->top==-1;}
    bool isFull(Stack* ptr)    {return ptr->top==ptr->size-1;}
    void push(Stack* ptr, string x){
        if(isFull(ptr))    cout<<"Overflow!\n";
        else{
            ptr->top++;
            ptr->arr[ptr->top]=x;
        }
    }
    void pop(Stack* ptr){
        if(isEmpty(ptr))    cout<<"!Element\n";
        else{
            string x=ptr->arr[ptr->top];
            ptr->top--;
        }
    }
    string Top(Stack* ptr)    {return ptr->arr[ptr->top];}
};
void reverse(string s){
    Stack *st=new Stack(s.length());
    for(int i=0;i<s.length();i++){
        string wrd="";
        while (s[i]!=' ' && i<s.length())    wrd+=s[i++];
        st->push(st,wrd);
    } while(!st->isEmpty(st)){
        cout<<st->Top(st)<<" ";
        st->pop(st);
    } cout<<endl;
}
int main(){
    string s="I'm a noob programmer!";
    reverse(s);
    return 0;
}