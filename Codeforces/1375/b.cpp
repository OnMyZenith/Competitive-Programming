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
    vector<vector<int>> a(n, vector<int>(m));
    bool fail = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if((i == 0 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1)) {
                if (a[i][j] > 2) fail = 1;
            } else if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                if (a[i][j] > 3) fail = 1;
            } else {
                if (a[i][j] > 4) fail = 1;
            }
        }
    }
    if (fail) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if((i == 0 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1)) {
                cout << 2 << " \n"[j == m - 1];
            } else if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                cout << 3 << " \n"[j == m - 1];
            } else {
                cout << 4 << " \n"[j == m - 1];
            }
        }
    }
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