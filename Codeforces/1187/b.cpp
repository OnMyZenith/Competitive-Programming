/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

// Check result <= hi
template <class T, class U> T ft(T lo, T hi, U f) {
    ++hi, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo) / 2;
        f(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n, m; string s; cin >> n >> s >> m;
    vector<vector<int>> f(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            f[i][j] = (i ? f[i - 1][j] : 0);
        }
        f[i][s[i] - 'a']++;
    }
    string t;
    for (int i = 0; i < m; i++) {
        cin >> t;
        vector<int> need(26);
        for (auto &c : t) {
            need[c - 'a']++;
        }
        cout << ft(0, n - 1, [&](int idx) -> bool {
            for (int j = 0; j < 26; j++) {
                if (need[j] > f[idx][j]) return false;
            }
            return true;
        }) + 1 << '\n';
    }

    return 0;
}