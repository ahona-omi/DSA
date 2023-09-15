/*to find a subsequence of elements in a 
queue that sums up to a given target value k*/

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
    int n=6,y,k,sum=0,i=0,j=0,tSum=0,Min=INT_MAX;
    cout<<"Enter k-> ";
    cin>>k;
    Queue q(n);
    cout<<"Enter queue\n";
    for(int i=0;i<n;i++){
        cin>>y;
        q.enqueue(y);
    } 
    for(int x=0;x<n;x++){
        tSum+=q.peek(x);
        Min=min(Min,q.peek(x));
    } if(k<Min || k>tSum){
        cout<<"Out of bound!"<<endl;
        return 0;
    } cout<<"I= "<<i<<"  J= "<<j<<"  Sum= "<<sum<<endl;
    for(i=0;i<n;i++){
        sum+=q.peek(i);
        if(q.peek(i)==Min && (sum-q.peek(i))==k) {
            sum-=q.peek(i);
            j=i+1;
        }
        if(sum>k)   break;
    } cout<<"I= "<<i<<"  J= "<<j<<"  Sum= "<<sum<<endl;
    if(sum>k){
        while(sum!=k)
            if(q.peek(j)>=0)    sum-=q.peek(j++);
            else    sum+=q.peek(j++);
    } else j=0;
    cout<<"I= "<<i<<"  J= "<<j<<"  Sum= "<<sum<<endl;
    // cout<<"Target subsequence:\n";
    // for(int l=j;l<=i;l++)     cout<<q.peek(l)<<" ";
    // cout<<endl;
    return 0;
}