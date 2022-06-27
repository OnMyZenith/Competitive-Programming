/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

void solve() {
    vector<int> a = {4, 8, 15, 16, 23, 42};
    int n = 6;
    vector<array<int, 4>> poss;
    vector<vector<int>> all;
    sort(a.begin(), a.end());
    do {
        array<int, 4> one;
        for (int i = 1; i < 5; i++) {
            one[i - 1] = a[i] * a[0];
        }
        poss.push_back(one);
        all.push_back(a);
    } while (next_permutation(a.begin(), a.end()));
    array<int, 4> res;
    for (int i = 1; i < 5; i++) {
        cout << "? 1 " << i + 1 << endl;
        cin >> res[i - 1];
    }
    for (int i = 0; i < (int)poss.size(); i++) {
        if (res == poss[i]) {
            cout << "!";
            for (int j = 0; j < n; j++) {
                cout << " " << all[i][j];
            }
            cout << endl;
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    // cin >> TT;
    while (TT--) {
        solve();
    }

    return 0;
}