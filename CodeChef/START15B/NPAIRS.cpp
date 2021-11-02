#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long double eps = 5e-8;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int res = 0;
    map<pair<int, bool>, int> mp;
    for (int i = 0; i < n; i++) {
        mp[{s[i] - i, true}]++;
        mp[{s[i] + i, false}]++;
    }
    for (auto x : mp) {
        int cnt = x.second;
        res += ((cnt * (cnt - 1)) / 2);
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}