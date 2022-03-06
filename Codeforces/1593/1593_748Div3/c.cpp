#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long double eps = 5e-8;

void solve() {
    ll n, k;
    cin >> n >> k;
    ll x[k];
    for (ll i = 0; i < k; i++) {
        ll tmp;
        cin >> tmp;
        x[i] = n - tmp;
    }
    sort(x, x + k);
    ll sum = 0, saved = 0;
    for (ll i = 0; i < k; i++) {
        if (sum + x[i] <= n - 1) {
            sum += x[i];
            saved++;
        } else
            break;
    }
    cout << saved << '\n';
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