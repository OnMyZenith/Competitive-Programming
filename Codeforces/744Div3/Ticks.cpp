#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    char s[n][m];
    bool valid = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> s[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '*') {
                if (i + 1 < n && j - 1 > 0 && j + 1 < n)
                    if (s[i + 1][j - 1] == '*' || s[i + 1][j + 1] == '*') continue;
                    else {
                        valid = false;
                        break;
                    }
                else if (i - 1 > 0 && j - 1 > 0 && j + 1 < n) {
                    if (s[i - 1][j - 1] == '*' && s[i - 1][j + 1] == '*' && i >= k) continue;
                    else {
                        valid = false;
                        break;
                    }
                }
            }
        }
        if (!valid) break;
    }
    if (valid) cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}