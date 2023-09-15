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
            if (isFull(ptr))      cout << "Overflow!\n";
            else{
                  ptr->top++;
                  ptr->arr[ptr->top] = x;
            }
      }
      void pop(Stack *ptr){
            if (isEmpty(ptr))      cout << "!Element\n";
            else{
                  int x = ptr->arr[ptr->top];
                  ptr->top--;
            }
      }
      int Top(Stack *ptr) { return ptr->arr[ptr->top]; }
};
vector<int> nxtGretEle(vector<int> v){
      vector<int> nge(v.size());
      Stack *st = new Stack(v.size());
      for (int i = 0; i < v.size(); i++){
            while (!st->isEmpty(st) && v[i] > v[st->Top(st)]){
                  nge[st->Top(st)] = i;
                  st->pop(st);
            } st->push(st, i);
      }
      while (!st->isEmpty(st)){
            nge[st->Top(st)] = -1;
            st->pop(st);
      } return nge;
}
int main(){
      int n;
      cin >> n;
      vector<int> v(n);
      for (int i = 0; i < n; i++)      cin >> v[i];
      vector<int> nge = nxtGretEle(v);
      for (int i = 0; i < n; i++)
            cout << v[i] << " " << (nge[i] == -1 ? -1 : v[nge[i]]) << endl;
      return 0;
}