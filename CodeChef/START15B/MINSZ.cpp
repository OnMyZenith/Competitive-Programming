#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long double eps = 5e-8;

vector<ll> sol(ll n, vector<ll> v) {
    ll tmp = n + 1;
    while (tmp % 2 == 0) {
        tmp /= 2;
    }
    if (tmp < 2) {
        v.push_back(n);
        return v;
    } else {
        ll p = 1;
        while (!(p > n))
            p *= 2;
        p--;
        ll r = p ^ n;
        v.push_back(p);
        return sol(r, v);
    }
}

void solve() {
    ll n;
    cin >> n;
    if (n == 0) {
        cout << 2 << '\n'
             << "1 1\n";
        return;
    }
    vector<ll> tmp;
    vector<ll> r = sol(n, tmp);
    cout << r.size() << '\n';
    for (ll i : r)
        cout << i << " ";
    cout << '\n';
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