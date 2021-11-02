#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int mex(int a[], int sz, int strt) {
    set<int> s;
    for (int j = 0; j < sz; j++)
        s.insert(a[j]);
    for (int i = strt;; i++) {
        auto it = s.begin();
        if (s.find(i) == s.end()) return i;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int dp[n][n];
    map<int, int> b;
    for (int i = 0; i < n; i++) {
        dp[i][i] = mex(a + i, 1, 0);
        b[dp[i][i]]++;
    }

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            if (dp[i][j - 1] != a[j])
                dp[i][j] = dp[i][j - 1];
            else
                dp[i][j] = mex(a + i, j - i + 1, a[j] + 1);
            b[dp[i][j]]++;
        }

    int cnt = 0;
    for (auto it = b.begin(); it != b.end(); it++)
        if (cnt + (*it).second >= k) {
            cout << (*it).first << '\n';
            break;
        } else
            cnt += (*it).second;
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