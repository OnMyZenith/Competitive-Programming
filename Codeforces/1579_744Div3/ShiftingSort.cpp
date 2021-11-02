#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int mx = a[0], mx_idx;
    for (int i = 0; i < n; i++) {
        if (mx < a[i]) mx = a[i];
        mx_idx = i;
    }
    // cout << n << '\n';
    int skip = 0;
    vector<pair<int, int>> moves;
    for (int i = 0; i < n; i++) {
        int mn = mx;
        int mn_idx = mx_idx;
        for (int j = i; j < n; j++)
            if (mn > a[j]) {
                mn = a[j];
                mn_idx = j;
            }
        if (mn_idx == i) skip++;
        else {
            moves.push_back(make_pair(i + 1, mn_idx + 1));
            for (int k = mn_idx; k > i; k--)
                a[k] = a[k - 1];
        }
    }
    cout << moves.size() << '\n';
    for (auto i : moves)
        cout << i.first << " " << i.second << " " << i.second - i.first << '\n';
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