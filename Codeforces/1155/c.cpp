/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n, m; cin >> n >> m;
    vector<ll> a(n); cin >> a[0];
    ll f = a[0];
    for (int i = 1; i < n; i++) cin >> a[i], a[i] -= a[0];
    a[0] = 0;
    vector<ll> p(m);
    for (auto &u : p) {
        cin >> u;
    }
    ll g = 0;
    for (int i = 1; i < n; i++) g = gcd(g, a[i]);

    dbg(g);

    if (g == 0) {
        cout << "YES\n";
        cout << f << " " << 1 << '\n';
        return 0;
    }
    for (int i = 0; i < m; i++) {
        if (g % p[i] == 0) {
            cout << "YES\n";
            cout << (!(f % p[i]) ? f : f % p[i]) << " " << i + 1 << '\n';
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}