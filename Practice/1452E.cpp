/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

const int N = 2007;
array<int, 2> q[N];
array<int, 2> _ans[N];
array<int, 2> ans[N][N];

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < m; i++) cin >> q[i][0] >> q[i][1], --q[i][0];

    sort(q, q + m, [&](array<int, 2> &a, array<int, 2> &b) -> bool {
        return a[0] + a[1] < b[0] + b[1];
    });

    for (int i = 0; i <= n - k; i++) {
        int e = i + k;
        for (int j = 0; j < m; j++) {
            ans[i][j + 1][0] = ans[i][j][0] + min({max(e - q[j][0], 0), max(q[j][1] - i, 0), k, q[j][1] - q[j][0]});
            ckmax(_ans[j + 1][0], ans[i][j + 1][0]);
        }
    }

    for (int i = 0; i <= n - k; i++) {
        int e = i + k;
        for (int j = m - 1; j >= 0; j--) {
            ans[i][j][1] = ans[i][j + 1][1] + min({max(e - q[j][0], 0), max(q[j][1] - i, 0), k, q[j][1] - q[j][0]});
            ckmax(_ans[j][1], ans[i][j][1]);
        }
    }

    int res = 0;
    for (int i = 0; i <= m; i++) {
        res = max(res, _ans[i][0] + _ans[i][1]);
    }

    cout << res << '\n';
    return 0;
}