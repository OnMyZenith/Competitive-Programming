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

    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<bool> inc(n - 1);
    vector<array<int, 2>> bad;
    for (int i = 0, t, l, r; i < m; i++) {
        cin >> t >> l >> r; l--, r--;
        if (t) {
            for (int j = l; j < r; j++) {
                inc[j] = 1;
            }
        } else {
            bad.push_back({l, r});
        }
    }
    for (auto &[l, r] : bad) {
        bool works = 0;
        for (int i = l; i < r; i++) {
            works |= !inc[i];
        }
        if (!works) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n1007 ";
    for (int i = 1, last = 1007; i < n; i++) {
        if (!inc[i - 1]) {
            cout << " " << --last;
        } else cout << " " << last;
    }
    cout << '\n';

    return 0;
}