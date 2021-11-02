#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    ll a[n], sumUpto[n], remUpto[n + 1];
    ll total = 0;
    remUpto[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
        sumUpto[i] = total;
        remUpto[i + 1] = sumUpto[i] % m;
    }
    map<int, vector<int>> remIdx;
    for (int i = 0; i <= n; i++)
        remIdx[remUpto[i]].push_back(i);
    for (auto it = remIdx.begin(); it != remIdx.end(); it++) {
        if ((*it).second.size() < 2) continue;
        else {
            for (int i = 0; i < (*it).second.size(); i++) {
                if ((*it).second[0] + 1 < (*it).second[1] && (*it).second[0] >= n / 2 - 1)
            }
        }
    }

    int res = n;
    for (int i = 0; i < n; i++) { //i = 0 means nothing removed from bottom
        int rem = remUpto[n - i];
        for (int j = 0; j <= i && j <= n - 1 - i; j++)
            if (remUpto[j] == rem && ((j & i) == j)) { //j = 0 means nothing removed from top
                res = i;
                break;
            }
        if (res != n) break;
    }
    if (res == n) cout << -1 << '\n';
    else {
        int cnt = 0;
        while (res) {
            cnt += res & 1;
            res >>= 1;
        }
        cout << cnt << '\n';
    }
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