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
    vector<vector<int>> a(n, vector<int>(m));
    auto b = a;
    for (auto &r : a) {
        for (auto &c : r) {
            cin >> c;
        }
    }
    // bool fail = 0;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         if (a[i][j]) {
    //             bool leftnotset = (j == 0 || a[i][j - 1] == 0);
    //             bool rightnotset = (j == m - 1 || a[i][j + 1] == 0);
    //             fail |= leftnotset && rightnotset;
    //         }
    //     }
    // }
    
    // for (int j = 0; j < m; j++) {
    //     for (int i = 0; i < n; i++) {
    //         if (a[i][j]) {
    //             bool upnotset = (i == 0 || a[i - 1][j] == 0);
    //             bool downnotset = (i == n - 1 || a[i + 1][j] == 0);
    //             fail |= upnotset && downnotset;
    //         }
    //     }
    // }
    // if (fail) {
    //     cout << "-1\n";
    //     return 0;
    // }

    vector<pair<int, int>> res;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (a[i][j] && a[i][j + 1] && a[i + 1][j] && a[i + 1][j + 1]) {
                res.push_back({i, j});
                b[i][j] = b[i][j + 1] = b[i + 1][j] = b[i + 1][j + 1] = 1;
            }
        }
    }
    if (a == b) {
        cout << (int)res.size() << '\n';
        for (auto &[x, y] : res) {
            cout << ++x << " " << ++y << '\n';
        }
    } else {
        cout << "-1\n";
        return 0;
    }

    return 0;
}