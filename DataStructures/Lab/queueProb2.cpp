#include<bits/stdc++.h>
using namespace std;

class Queue{
private:
    int *arr;
    int front,rear,size;
public:
    Queue(int S){
        front = 0;
        rear = -1;
        size = S;
        arr = new int[size];
    }
    ~Queue()    {delete[] arr;}
    void enqueue(int x){
        if(isFull())    cout<<"oVERFLOW"<<endl;
        else{
            rear++;
            arr[rear]=x;
        }
    }
    int dequeue(){
        int a=-1;
        if(isEmpty())   cout<<"No element"<<endl;
        else{
            //front++;
            a=arr[rear--];
        } return a;
    }
    int peek(int in){
        if(isEmpty() || in>=size){
            cout<<"!Valid"<<endl;
            return -1;
        } return arr[in];
    }
    bool isFull()       {return (rear == size - 1 || front == size);}
    bool isEmpty()      {return (rear == -1 && front == 0);}
};
int main(){
    int n=6,y,k,sum=0,i,j=0,tSum=0,Min=INT_MAX,len=0;
    cout<<"Enter k-> ";
    cin>>k;
    Queue q(n);
    cout<<"Enter queue:\n";
    for(int i=0;i<n;i++){
        cin>>y;
        q.enqueue(y);
    } 
    for(int x=0;x<n;x++){
        tSum+=q.peek(x);
        Min=min(Min,q.peek(x));
    } if(k<Min ){
        cout<<"Out of bound!"<<endl;
        return 0;
    }
    for(i=0;i<n;i++){
        sum+=q.peek(i);
        len++;
        if(sum>=k)   break;
    }  if(sum>k){
        while(sum!=k){
            sum-=q.peek(j++);
            len--;
        }
    } else j=0;
    if(len==0)  cout<<"No subsequence found"<<endl;
    else{
        cout<<"Target subsequence:"<<endl;
        for(int l=j;l<=i;l++)     cout<<q.peek(l)<<" ";
        cout<<endl;
    }
    return 0;
}