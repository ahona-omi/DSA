#include <bits/stdc++.h>

using namespace std;

void Swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
int Min(int a[], int n){
    int mn=a[0];
    for(int i=1;i<n;i++){
        if(a[i]<mn)    mn=a[i];
    } return mn;
}
int Max(int a[], int n){
    int mx=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>mx)    mx=a[i];
    } return mx;
}
void display(float a[], int n){
    cout<<"ki re sajanno hoyche: ";
    for(int i=0;i<n;i++)  cout<<a[i]<<" ";
    cout<<endl;
}

void bubbleS(int a[], int n){
    for(int i=0;i<n-1;i++){
        int flag=0;
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                Swap(&a[j],&a[j+1]);
                flag=1;
            }
        } if(flag==0)   break;
    }
}

void insertionS(int a[], int n){
    for(int i=1;i<n;i++){
        int temp=a[i], j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        } a[j+1]=temp;
    }
}

void selectionS(int a[], int n){
    for(int i=0;i<n-1;i++){
        int mn=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[mn])  mn=j;
        } if(mn!=i)    Swap(&a[i],&a[mn]);
    }
}

void PCountS(int a[], int n){
    int k=Max(a,n), cnt[k+1]={0},b[n];
    for(int i=0;i<n;i++)    ++cnt[a[i]];
    for(int i=1;i<=k;i++)    cnt[i]+=cnt[i-1];
    for(int i=n-1;i>=0;i--)    b[--cnt[a[i]]]=a[i];
    for(int i=0;i<n;i++)    a[i]=b[i];
}
void NCountS(int a[], int n){
    int mn=Min(a,n), mx=Max(a,n);
    for(int i=0;i<n;i++)    a[i]-=mn;
    int k=mx-mn,cnt[k+1]={0},b[n];
    for(int i=0;i<n;i++)    ++cnt[a[i]];
    for(int i=1;i<=k;i++)    cnt[i]+=cnt[i-1];
    for(int i=n-1;i>=0;i--)    b[--cnt[a[i]]]=a[i];
    for(int i=0;i<n;i++)    a[i]=b[i]+mn;
}

void bucketS(float arr[], int n){
    vector<float> b[n];
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    } for (int i = 0; i < n; i++)    sort(b[i].begin(), b[i].end());
    int index = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
    }
}

int partion4QS(int a[], int lb, int ub){
    int pivot=a[lb], strt=lb, end=ub;
    while(strt<end){
        while(a[strt]<=pivot)   strt++;
        while(a[end]>pivot)   end--;
        if(strt<end)    Swap(&a[strt],&a[end]);
    } Swap(&a[lb],&a[end]);
    return end;
}
int LTpartion4QS(int a[], int lb, int ub){
    int pivot=a[ub], i=lb-1;
    for(int j=lb;j<ub;j++){
        if(a[j]<pivot){
            i++;
            Swap(&a[i],&a[j]);
        } 
    } Swap(&a[i+1],&a[ub]);
    return i+1;
}
void quickS(int a[], int lb, int ub){
    if(lb<ub){
        int loc=partion4QS(a, lb, ub);
        //int loc=LTpartion4QS(a, lb, ub);
        quickS(a,lb,loc-1);
        quickS(a,loc+1,ub);
    }
}

void merge(int a[], int lb, int mid, int ub){
    int i=lb, j=mid+1, k=lb, b[ub-lb+1];
    while(i<=mid && j<=ub){
        if(a[i]<=a[j])  b[k]=a[i++];
        else    b[k]=a[j++];
        k++;
    } if(i>mid){
        while(j<=ub)    b[k++]=a[j++];
    } else{
        while(i<=mid)    b[k++]=a[i++];
    } for(int x=lb;x<=ub;x++)   a[x]=b[x];
}
void mergeS(int a[], int lb, int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        quickS(a,lb,mid);
        quickS(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}

int main() {
    int a[]={69,420,-69,-420,0,69};
    int c[]={69,420,9,20,0,69};
    float b[]={0.69,0.42,0.9,0.2,0,0.96};
    int n=sizeof(b) / sizeof(b[0]);
    //bubbleS(a,n);
    //insertionS(a,n);
    //selectionS(a,n);
    //quickS(a,0,n-1);
    //mergeS(a,0,n-1);
    //NCountS(a,n);
    //PCountS(c,n);
    bucketS(b,n);
    display(b,n);
    return 0;
}
