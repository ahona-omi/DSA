#include<bits/stdc++.h>
using namespace std;
//const int N=1e9+7;
//typedef long long int ll;

void Swap(int* a, int* b) {
    int t=*a;
    *a=*b;
    *b=t;
}
void print(int arr[], int n){
    cout<<"Binary Max Heap: ";
    for (int i = 0; i < n; ++i)    cout << arr[i] << " ";
    cout << endl;
}
void insert(int arr[], int& size, int key) {        //O(log n)
    int childIn = size;
    arr[childIn] = key;
    while (childIn > 0) {
        int parentIn = (childIn - 1) / 2;
        if (arr[childIn] > arr[parentIn]) {
            Swap(&arr[childIn], &arr[parentIn]);
            childIn = parentIn;
        } else    break;
    } size++;
}
void heapify(int arr[], int n, int i){
    if(i>=n || i<0)    return;
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])    largest = l;
    if (r < n && arr[r] > arr[largest])    largest = r;
    if (largest != i) {
        Swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n){
    //build max heap
    for (int i = n / 2 - 1; i >= 0; i--)    heapify(arr, n, i);
    //delete
    for (int i = n - 1; i > 0; i--) {
        Swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
void delRoot(int arr[], int& n){
    int x=0;
    for(int i=0;i<n;i++)    insert(arr,x,arr[i]);
    int lastElement = arr[n - 1];
    arr[0] = lastElement;
    n = n - 1;
    heapify(arr, n, 0);
}
void merge2Heaps(int merged[], int a[], int b[], int N, int M){
    for (int i = 0; i < N; i++)    merged[i] = a[i];
    for (int i = 0; i < M; i++)    merged[N + i] = b[i];
    for (int i = (N+M) / 2 - 1; i >= 0; i--)
        heapify(merged, N+M, i);
}
int main(){
    int n=5,m=3,l, mrg[n+m],x=0,y;
    int a[n]={10,20,15,30,40};
    int b[m]={12,7,9};
    // for(int i=0;i<n;i++){
    //     cin>>y;
    //     insert(a,x,y);
    // } print(a,n);
    for(int i=0;i<n;i++)    insert(a,x,a[i]);
    insert(a,n,69);
    print(a,n);
    delRoot(a,n);
    print(a,n);
    heapSort(a,n);
    print(a,n);
    merge2Heaps(mrg,a,b,n,m);
    print(mrg,n+m);
    return 0;
}