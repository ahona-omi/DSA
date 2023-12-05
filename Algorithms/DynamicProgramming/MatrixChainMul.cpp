#include <bits/stdc++.h>
using namespace std;

const int N = 100;

void matrixChainOrder(int n, int p[], int m[N][N], int s[N][N]) {
    // Initialize table m[i,j]
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0; //diagonal elms = 0
    }

    // Calc m[i,j]
    for (int l = 2; l <= n; l++) { // l = chain length  //start from 2 jate i,j diagonally calc kore kore next step e jai
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1; 
            m[i][j] = INT_MAX; //initialize before compare min

            // Try difrnt split points within the chain & find mini cost
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (q < m[i][j]) {
                    m[i][j] = q;// min
                    s[i][j] = k; // best split point
                }
            }
        }
    }
}

void print_Optimal_Parenthesis(int s[N][N], int i, int j) {
    if (i == j) {
        cout << "A" << i<<" ";
    } else {
        cout << "(";
        print_Optimal_Parenthesis(s, i, s[i][j]); // print left sub-chain
        print_Optimal_Parenthesis(s, s[i][j] + 1, j); // right sub-chain
        cout << ")";
    }
}

int main() {
    int n;
    cin>>n;
    int p[N];
    for(int i=0;i<=n;i++)    cin>>p[i];

    int m[N][N]; // Cost table = m[i,j]
    int s[N][N]; // Split table = k[i,j]

    matrixChainOrder(n, p, m, s);

    cout << "Minimum number of multiplications: " << m[1][n] << endl;
    cout << "Optimal Parenthesization: ";
    print_Optimal_Parenthesis(s, 1, n);
    cout << endl;

    return 0;
}
