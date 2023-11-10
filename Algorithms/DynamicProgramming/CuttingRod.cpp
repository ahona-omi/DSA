#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int dp[1005];

//Unbounded knapsack
int recursive(int len, vector<int> &prices){
	if(len==0)	return 0;
	int ans=INT_MIN;
	for(int i=1; i<=prices.size(); ++i){
		if(len-i>=0)
			ans=max(ans, prices[i-1] +recursive(len-i, prices));
	}
	return ans;
}

//O(n^2)
int memoisation(int len, vector<int> &prices){
	if(len==0)	return 0;
	if(dp[len]!=-1)	return dp[len];

	int ans=INT_MIN;
	for(int i=1; i<=prices.size(); ++i){
		if(len-i>=0)
			ans=max(ans, prices[i-1] +memoisation(len-i, prices));
	}
	return dp[len]=ans;
}

int bottom_up(int n, vector<int> &prices){
	dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] = max(dp[i], prices[j - 1] + dp[i - j]);
        }
    }
	
    return dp[n];
}

void cutRod(int price[], int n) {

    memset(dp, -1, sizeof(dp));


    vector<int> prices(price, price + n);

// Calculate results for all three functions
	auto start1 = chrono::high_resolution_clock::now();
    int maxProfitRecursive = recursive(n, prices);
	auto end1 = chrono::high_resolution_clock::now();
	chrono::duration<double, nano> time1 = end1 - start1;
	cout << "Rod Cutting using recursive-"<< maxProfitRecursive<<endl;
	cout << "Time for recursive: " << time1.count() << " nanoseconds" <<endl<<endl;

	auto start2 = chrono::high_resolution_clock::now();
    int maxProfitMemoisation = memoisation(n, prices);
	auto end2 = chrono::high_resolution_clock::now();
	chrono::duration<double, nano> time2 = end2 - start2;
	cout << "Rod Cutting using memoisation-"<< maxProfitMemoisation<<endl;
	cout << "Time for memoisation: " << time2.count() << " nanoseconds" <<endl<<endl;

    auto start3 = chrono::high_resolution_clock::now();
    int maxProfitBottomUp = bottom_up(n, prices);
	auto end3 = chrono::high_resolution_clock::now();
	chrono::duration<double, nano> time3 = end3 - start3;
	cout << "Rod Cutting using memoisation-"<< maxProfitMemoisation<<endl;
	cout << "Time for memoisation: " << time3.count() << " nanoseconds" <<endl<<endl;
}

int main(){
	int n;
	cin >> n;
	int files[n];
	for (int i = 0; i < n; ++i) cin >> files[i];
	
	cutRod(files,n);

	return 0;
}
