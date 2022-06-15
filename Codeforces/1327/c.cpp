/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n, m, k; cin >> n >> m >> k;
    vector<array<int, 2>> s(k), e(k);
    for (int i = 0; i < k; i++) cin >> s[i][0] >> s[i][1];
    for (int i = 0; i < k; i++) cin >> e[i][0] >> e[i][1];

    cout << 2 * n * m - 2 << '\n';
    for (int j = 0; j < m - 1; j++) {
        cout << "L";
    }
    for (int j = 0; j < m - 1; j++) {
        cout << "R";
    }
    for (int i = 0; i < 2 * (n - 1); i++) {
        cout << (i < n - 1 ? "D" : "U");
        for (int j = 0; j < m - 1; j++) {
            cout << (i & 1 ? "R" : "L");
        }
    }
    cout << '\n';

    return 0;
}