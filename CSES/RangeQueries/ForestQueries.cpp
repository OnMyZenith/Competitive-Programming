/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

const int N = 1007;
bool g[N][N];
int pre[N][N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n, q; cin >> n >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            g[i][j] = c == '*';
            pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] + g[i][j] - pre[i][j];
        }
    }

    while (q--) {
        int y1, y2, x1, x2; cin >> x1 >> y1 >> x2 >> y2;
        cout << pre[x2][y2] + pre[x1 - 1][y1 - 1] - pre[x2][y1 - 1] - pre[x1 - 1][y2] << '\n';
    }

    return 0;
}