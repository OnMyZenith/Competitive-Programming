/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif




void solve() {
    int n, m; cin >> n >> m;
    vector<vector<bool>> a(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = (s[j] == '1');
        }
    }
    if(a[0][0]) {
        cout << "-1\n";
        return;
    }
    vector<vector<int>> res;
    res.reserve(n*m);
    for (int k = 0; k <= max(n - 1, m - 1); k++) {
        int r = min(k, n - 1), c = min(k, m - 1);

        if(r >= 0 && c >= 0 && r <= n - 1 && c <= m - 1 && a[r][c]) {
            cout << "-1\n";
            return;
        }
        dbg(r, c);
        for (int i = 0; i <= r && c >= 0 && c < m - 1; i++) {
            if(a[i][c + 1]) {
                a[i][c + 1] = 0;
                // dbg(r + 1, c + 1);
                res.push_back({i, c, i, c + 1});
            }
        }
        for (int j = 0; j <= c && r >= 0 && r < n - 1; j++) {
            if(a[r + 1][j]) {
                a[r + 1][j] = 0;
                // dbg(r + 1, c + 1);
                res.push_back({r, j, r + 1, j});
            }
        }
        if(r >= 0 && c >= 0 && r <= n - 2 && c <= m - 2 && a[r + 1][c + 1]) {
            a[r + 1][c + 1] = 0;
            res.push_back({r + 1, c, r + 1, c + 1});
        }
    }
    cout << (int)res.size() << '\n';
    if(res.empty()) return;
    reverse(res.begin(), res.end());
    for (auto &r : res) {
        cout << r[0] + 1 << " " << r[1] + 1 << " " << r[2] + 1 << " " << r[3] + 1 << '\n';
    }
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}