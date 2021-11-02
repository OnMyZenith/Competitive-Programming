#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long double eps = 5e-8;

ll minArr(ll a[], ll n) {
    if (n == 2) return min(a[0], a[1]);
    return min(a[n - 1], minArr(a, n - 1));
}

void solve() {
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll mn = minArr(a, n);
    for (ll i = 0; i < n; i++)
        a[i] -= mn;

    ll gc = 0;
    for (ll i = 0; i < n; i++)
        gc = gcd(a[i], gc);
    if (gc == 0)
        cout << -1 << '\n';
    else
        cout << gc << '\n';
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