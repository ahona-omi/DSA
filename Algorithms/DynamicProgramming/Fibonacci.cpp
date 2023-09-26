#include <bits/stdc++.h>
using namespace std;

const int N= 1e7+10;
int dp[N];

//--------O(2^n)
int fibonacci(int n){
    if(n==0)    return 0;
    if(n==1)    return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}

//----------O(n)
int fibonacciDp(int n){
    if(n==0)        return 0;
    if(n==1)        return 1;
    if(dp[n] != -1) return dp[n];
//memoise(Top-down)
    return dp[n]=fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    memset(dp,-1,sizeof(dp));
	int n;
    cin >> n;
    cout<<fibonacciDp(n)<<endl;
    //cout<<n<<" th Fibonacci number: "<<fibonacci(n)<<endl;
	return 0;
}

/*
General - Dp
O(2^n)--> O(n)
O(n!)--> O(2^n) -------Bit masking dp
*/
