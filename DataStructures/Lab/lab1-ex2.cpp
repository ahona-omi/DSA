/*a search algorithm to find a target element x in a 
rotated sorted array v in a modified binary search approach*/

#include<bits/stdc++.h>

using namespace std;
const int N=1e9+7;
typedef long long int ll;

bool search(vector<int> &v, int x){
    int lft=0,rgt=v.size()-1;
    if(v.size()==0) return 0;
    while(lft<=rgt){ 
        int mid=(lft+rgt)/2;
        if(v[mid]==x)    return 1;
        else if(v[lft]<v[mid]){
            if(x>=v[lft] && x<=v[mid])    rgt=mid-1;
            else    lft=mid+1;
        }
        else if(v[mid]<v[lft]){
            if(x>=v[mid] && x<=v[rgt])    lft=mid+1;
            else   rgt=mid-1;
        } else    lft++;
    } return 0;
}

int main(){
    vector<int> v{3,1,2,3,3,3,3}; //2,5,6,0,0,1,2
    int x=2;
    cout<<search(v,x)<<endl;
    return 0;
}