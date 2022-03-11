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
            a[i][j] = s[j] == '1';
        }
    }
    // 2 X 2
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if(!a[i][j] && a[i][j + 1] && a[i + 1][j] && a[i + 1][j + 1]) {
                cout << "NO\n";
                return;
            }
            if(a[i][j] && !a[i][j + 1] && a[i + 1][j] && a[i + 1][j + 1]) {
                cout << "NO\n";
                return;
            }
            if(a[i][j] && a[i][j + 1] && !a[i + 1][j] && a[i + 1][j + 1]) {
                cout << "NO\n";
                return;
            }
            if(a[i][j] && a[i][j + 1] && a[i + 1][j] && !a[i + 1][j + 1]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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