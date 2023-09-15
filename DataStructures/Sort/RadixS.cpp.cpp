#include<bits/stdc++.h>
#include<chrono>

using namespace std;
const int N=1e9+7;
typedef long long int ll;

void countS(int a[], int n, int pos){
    int cnt[10]={0};
    int b[n];
    for(int i=0;i<n;i++){
        ++cnt[(a[i]/pos)%10];
    } for(int i=1;i<10;i++){
        cnt[i]=cnt[i]+cnt[i-1];
    } for(int i=n-1;i>=0;i--){
        b[--cnt[(a[i]/pos)%10]]=a[i];
    } for(int i=0;i<n;i++){
        a[i]=b[i];
    }
}

void selectionS(int a[], int n,int pas){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if((a[j]/pas)%10<(a[min]/pas)%10) min=j;
        } if(min!=i) swap(a[i],a[min]);
    }
}

void merge(int a[], int lb, int mid, int ub, int pos) {
    int i = lb, j = mid+1, k = 0;
    int ans[ub-lb+1];
    while(i<=mid && j<=ub){
        if((a[i]/pos)%10<=(a[j]/pos)%10){
            ans[k++]=a[i++];
        } else{
            ans[k++]=a[j++];
        }
    }
    while(i<=mid) ans[k++]=a[i++];
    while(j<=ub) ans[k++]=a[j++];
    for (int i = 0; i < ub-lb+1; i++)    a[i+lb]= ans[i];
}
void mergeS(int a[], int lb, int ub, int pos) {
    if (lb < ub) {
        int m = (lb+ub) / 2;
        mergeS(a, lb, m, pos);
        mergeS(a, m + 1, ub, pos);
        merge(a, lb, m, ub, pos);
    }
}

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
int partiton(int arr[],int low,int high, int exp){
    int pivot = (arr[low]/exp)%10;
    int i = low-1, j = high+1;
    while(1){
        i++;
        while((arr[i]/exp)%10 < pivot) i++;
        j--;
        while((arr[j]/exp)%10>pivot) j--;
        if(i>=j) return j;
        swap(&arr[i],&arr[j]);
    }
}
void quickS(int arr[],int low,int high, int exp){
    if(low>=high) return;
    int p =  partiton(arr,low,high,exp); 
    quickS(arr,low,p,exp); 
    quickS(arr,p+1,high,exp);
}

void radix(int a[],int n){
    int max=*max_element(a,a+n);
    for(int pass=1;(max/pass)>0;pass*=10){
        //countS(a,n,pass);
        //selectionS(a,n,pass);
        //mergeS(a,0,n-1,pass);
        quickS(a,0,n-1,pass);
    }
    
}

int main(){
    int n=7000;
    //cin>>n;
    int rndmInt[n];
    fstream file1("input.txt",ios::out);
    fstream file2("output.txt",ios::out);
    int p=99999-10000+1;
    for(int i=0;i<n;i++){
        rndmInt[i]=((rand()%p)+10000);
        file1<< rndmInt[i] << " ";
    } file1.close();
    auto start = chrono::high_resolution_clock::now();
    radix(rndmInt,n);
    for(int i=0;i<n;i++){
        file2<<rndmInt[i]<<" ";
    } file2<<endl;
    auto end = chrono::high_resolution_clock::now();
    auto time = chrono::duration_cast<chrono::microseconds>(end-start);
    cout << "Total time: "<<time.count() <<" micro sec"<< endl;
    file2.close();
    return 0;
}