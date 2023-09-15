/*sort each diagonal line of elements from the top-left 
corner to the bottom-right corner of the matrix*/

#include <bits/stdc++.h>

using namespace std;
const int N = 1e9 + 7;
typedef long long int ll;
bool comp(ll a, ll b)  {return a>b;}

vector<vector<int>> diagonalSort(vector<vector<int>> &a){
    int r = a.size();
    int c = a[0].size();
    vector<int> die;
    for (int k = 0; k < r; k++){
        die.clear();
        for (int j = 0, i = k; j < c && i < r; i++, j++)    die.push_back(a[i][j]);
        sort(die.begin(), die.end());
        for (int j = 0, i = k; j < c && i < r; i++, j++)    a[i][j] = die[j];
    }
    for (int k = 1; k < c; k++){
        die.clear();
        for (int i = 0, j = k; i < r && j < c; i++, j++)    die.push_back(a[i][j]);
        sort(die.begin(), die.end());
        for (int i = 0, j = k; i < r && j < c; i++, j++)    a[i][j] = die[i];
    }
    return a;
}

int main(){
    vector<vector<int>> a{{3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2}};
    diagonalSort(a);
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            cout << a[i][j] << " ";
        }  cout<<endl;
    } cout<<endl;
    return 0;
}