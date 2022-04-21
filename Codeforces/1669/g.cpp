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
    vector<vector<bool>> stones(n, vector<bool>(m));
    vector<string> ans(n, string(m, '.'));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            stones[i][j] = s[j] == '*';
            if(s[j] == 'o') ans[i][j] = 'o';
        }
    }
    // dbg(ans);
    vector<vector<int>> pre(m, vector<int> (n + 1));
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            pre[j][i + 1] = pre[j][i] + stones[i][j];
        }
        int l = 0;
        // dbg(ans);
        for (int i = 0; i < n; i++) {
            if(ans[i][j] == 'o') {
                int cnt = pre[j][i] - pre[j][l];
                l = i;
                for (int k = 1; k <= cnt; k++) {
                    ans[i - k][j] = '*';
                }
            }
            if(i == n - 1 && ans[i][j] != 'o') {
                int cnt = pre[j][n] - pre[j][l];
                for (int k = 1; k <= cnt; k++) {
                    ans[n - k][j] = '*';
                }
            }
        }
    }
    for (auto &u : ans) {
        cout << u << '\n';
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