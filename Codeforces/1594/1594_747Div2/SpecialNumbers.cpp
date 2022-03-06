#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1000000007;

ll pw(ll n, ll p) {
    if (p == 0) return 1;
    return (n * pw(n, p - 1)) % MOD;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    n %= MOD;
    ll res = 0, p = 0;
    while (k) {
        if (k % 2) res += ((ll)pw(n, p));
        res %= MOD;
        k = k >> 1;
        p++;
    }
    cout << res << "\n";
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