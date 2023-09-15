#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
    double d1 = (double)p1.first/p1.second;
    double d2 = (double)p2.first/p2.second;

    return d1 > d2;
}
double knapSack(vector<pair<int,int>> ele, int n,int w){
    double cpct=0;
    sort(ele.begin(), ele.end(), compare);

    for(int i = 0; i < n;i++){
        if(w>0 && ele[i].second <=w){
            w-=ele[i].second;
            cpct+=ele[i].first;
        } else if (w > 0) {
            cpct += (double)ele[i].first / ele[i].second * w;
            break;  // We've used up all the capacity
        }
    }
    return cpct;
}
int main() {
    int n,w;
    cin >>w>> n;
    vector<pair<int,int>> ele;
    ele.resize(n);     //Profit,weight
    for(int i = 0; i < n;i++)
        cin>>ele[i].first>>ele[i].second;
    cout<<knapSack(ele,n,w)<<endl;

    return 0;
}
