/*a binary search algorithm to find an
element x in a rotated sorted array v.*/

#include<bits/stdc++.h>
using namespace std;
const int N=1e9+7;
typedef long long int ll;

int rotAr(vector<int> &v,int lft, int rgt, int x){
        if(lft>rgt)    return -1;
        int mid=(lft+rgt)/2;
        if(v[mid]==x)    return mid;
        if(v[lft]<=v[mid]){
            if(x>=v[lft] && x<=v[mid])    return rotAr(v,lft,mid-1,x);
            return rotAr(v,mid+1,rgt,x);
        }
        if(x>=v[mid] && x<=v[rgt])    return rotAr(v,mid+1,rgt,x);
        return rotAr(v,lft,mid-1,x);
    }

int main(){
    vector<int> v{4,5,6,7,0,1,2};
    int x=0;
    cout<<rotAr(v,0,v.size()-1,x)<<endl;
    return 0;
}