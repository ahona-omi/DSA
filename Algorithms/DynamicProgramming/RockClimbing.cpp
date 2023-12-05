#include <bits/stdc++.h>
using namespace std;
vector<int> bestPath;

int BestPath_Rating(vector<vector<int>>& C) {
    int n = C.size();//row
    int m = C[0].size();//coln

    // Initialize  A[n+1, m+2]
    vector<vector<int>> A(n + 1, vector<int>(m + 2, INT_MAX));
    for (int j = 1; j <= m; j++) {
        A[0][j] = 0;//first row
    }
    //calc A
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            A[i][j] = C[i-1][j-1] + min({A[i-1][j-1], A[i-1][j], A[i-1][j+1]});
        }
    }
    //__________________bestRating________________________
    int bestRating = INT_MAX;
    //last row te
    for (int j = 1; j <= m; j++) {
        bestRating = min(bestRating, A[n][j]);
    }
    cout << "Rating of the best path = " << bestRating << endl;
    
    //____________________path___________________________
    //backtract to find the Path
    //find coln of bestRating
    int k;
    for (int j = 1; j <= m; j++) {
        if(A[n][j] == bestRating){
            k=j;
            break;
        }
    }
    //find the bestPath
    int elm =bestRating;//bestRating
    for (int i = n; i > 0; i--) {
        int temp = min({A[i-1][k-1],A[i-1][k],A[i-1][k+1]});
        elm=elm - temp;
        bestPath.push_back(elm);
        elm=temp;
    }
    //print bestPath
    cout << "Best path = ";
    for (int i=0;  i < bestPath.size(); i++) {
        cout << bestPath[i]<<"  ";
    }
    cout << endl;

    return bestRating;
}

int main() {
    int r,c;
    cin >> r >> c;
    vector<vector<int>> C(r, vector<int>(c));
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++)    cin >> C[i][j];
    }
    BestPath_Rating(C);

    return 0;
}