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
    int n, m; cin >> n >> m;
    vector<vector<array<int, 2>>> cnt(n, vector<array<int, 2>>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cnt[i][j][0];
            cnt[i][j][1] = cnt[i][j][0];
            if (i || j) {
                cnt[i][j][0] += min(j ? cnt[i][j - 1][0] : int(1e9), i ? cnt[i - 1][j][0] : int(1e9));
                cnt[i][j][1] += max(i ? cnt[i - 1][j][1] : int(-1e9), j ? cnt[i][j - 1][1] : int(-1e9));
            }
        }
    }
    dbg(cnt);
    if ((n + m - 1) & 1) {
        cout << "NO\n";
        return;
    }
    cout << ((cnt[n - 1][m - 1][1] >= 0) && (cnt[n - 1][m - 1][0] <= 0) ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}