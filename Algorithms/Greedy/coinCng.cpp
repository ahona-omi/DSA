#include <bits/stdc++.h>
using namespace std;

void minCoin(int denomination[],int n,int V){
    sort(denomination, denomination + n);
	vector<int> ans;

	for (int i = n - 1; i >= 0; i--) {
		while (V >= denomination[i]) {
			V -= denomination[i];
			ans.push_back(denomination[i]);
		}
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}

int main(){
	int n,x;
    cin >>n;
    int denomination[n];
    for (int i = 0; i < n; i++)   cin>> denomination[i];
    cin >> x;

	minCoin(denomination,n,x);
	return 0;
}
