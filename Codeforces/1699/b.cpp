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
    a[0][0] = a[1][1] = 1;
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m / 2; j++) {
            if (i == 0 && j == 0) continue;
            if (i > 0) {
                a[2 * i][2 * j] = a[2 * i - 1][2 * j];
                a[2 * i][2 * j + 1] = a[2 * i - 1][2 * j + 1];
                
                a[2 * i + 1][2 * j] = a[2 * i - 2][2 * j];
                a[2 * i + 1][2 * j + 1] = a[2 * i - 2][2 * j + 1];
            } else {
                a[2 * i][2 * j] = a[2 * i][2 * j - 1];
                a[2 * i + 1][2 * j] = a[2 * i + 1][2 * j - 1];
                
                a[2 * i][2 * j + 1] = a[2 * i][2 * j - 2];
                a[2 * i + 1][2 * j + 1] = a[2 * i + 1][2 * j - 2];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " \n"[j == m - 1];
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