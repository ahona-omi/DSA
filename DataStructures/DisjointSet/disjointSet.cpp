#include <bits/stdc++.h>
using namespace std;

class disjointSet{
private:
    vector<int> parent,Size, rank;
public:
    disjointSet(int n) {
        parent.resize(n+1);
        //rank.resize(n+1,0);
        Size.resize(n+1, 1);
        for (int i = 0; i <= n; i++)    parent[i] = i;
    }
    int find(int v){
        if(parent[v]==v) return v;
        //path compression->O(log n)       return parent[v]=find(parent[v]);
    }
    void Union(int a, int b){
        a=find(a);
        b=find(b);
        if(a!=b){
            if(Size[a]<Size[b])     swap(a,b);
            //if(rank[a]<rank[b])     swap(a,b);
            parent[b]=a;

            Size[a]+=Size[b];
            //if(rank[a]==rank[b])     rank[a]++;
            
        }
    }
};

int main(){
    disjointSet uf(7);
    uf.Union(1, 2);
    uf.Union(2, 3);
    uf.Union(4, 5);
    uf.Union(6, 7);
    uf.Union(5, 6);
    if(uf.find(3)==uf.find(7))    cout<<"same"<<endl;
    else    cout<<"!same"<<endl;
    uf.Union(3, 7);
    if(uf.find(3)==uf.find(7))    cout<<"same"<<endl;
    return 0;
}

/*  time complexity O(a(n))->Amortized time complexity
(average time taken per operation, nearly constant)
a(n)->reverse ackermann function(slowly increasing)
(The optimal algorithm for the Union-Find problem runs in time O(mα(n) + n),
  n =number of elements, m =total number of Union and Find operations performed.)  */