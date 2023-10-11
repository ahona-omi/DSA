#include <bits/stdc++.h>
using namespace std;

long long powerMod(long long A, long long k, long long mod) {
    if (k == 0) {
        return 1;
    }

    if (k % 2 == 0) {
        // If k is even, A^k = (A^(k/2))^2 mod mod
        long long halfPower = powerMod(A, k / 2, mod);
        return (halfPower * halfPower) % mod;
    } else {
        // If k is odd, A^k = A * (A^(k-1)) mod mod
        return (A * powerMod(A, k - 1, mod)) % mod;
    }
}

int main() {
    long long A, k, mod;
    cout << "Enter A, k, and mod: ";
    cin >> A >> k >> mod;

    long long result = powerMod(A, k, mod);
    cout << "A^k mod mod is: " << result << endl;

    return 0;
}
