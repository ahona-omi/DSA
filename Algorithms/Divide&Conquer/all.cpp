#include <bits/stdc++.h>
using namespace std;

class ChronoStone {
public:
    int age;
    int index;

    bool operator<(const ChronoStone &other) const {
        return age < other.age;
    }
};

vector<pair<int, int>> countInversions(vector<ChronoStone>& stones) {
    int n = stones.size();
    vector<pair<int, int>> inversionPairs;

    for (int i = 0; i < n; i++) {
        if (stones[i].age < 0) {
            for (int j = i + 1; j < n; j++) {
                if (stones[j].age > 0) {
                    inversionPairs.push_back({stones[i].index, stones[j].index});
                }
            }
        }
    }
    sort(inversionPairs.begin(), inversionPairs.end());
    return inversionPairs;
}

void print(vector<ChronoStone>& stones){
    sort(stones.begin(), stones.end());
    vector<pair<int, int>> inversionPairs = countInversions(stones);
    int inversions = inversionPairs.size();
    cout << inversions << endl;

    for (const pair<int, int> &invPair : inversionPairs)
        cout << invPair.first << " " << invPair.second << endl;

}
int main() {
    int n;
    cin >> n;

    vector<ChronoStone> stones(n);
    for (int i = 0; i < n; i++) {
        cin >> stones[i].age;
        stones[i].index = i;
    }
    print(stones);
    return 0;
}
