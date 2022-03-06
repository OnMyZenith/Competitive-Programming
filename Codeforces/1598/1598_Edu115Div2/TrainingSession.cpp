#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    ll a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cin >> b[i];
    }
    map<ll, ll> t_freq, d_freq;
    for (int i = 0; i < n; i++) {
        t_freq[a[i]]++;
        d_freq[b[i]]++;
    }
    ll excl = 0;
    for (int i = 0; i < n; i++) {
        if (t_freq[a[i]] > 1 && d_freq[b[i]] > 1) {
            excl += (t_freq[a[i]] - 1) * (d_freq[b[i]] - 1);
            t_freq[a[i]]--;
            d_freq[b[i]]--;
        }
    }
    ll res = ((n * (n - 1) * (n - 2)) / 6) - (excl);
    if (res < 0) res = 0;
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