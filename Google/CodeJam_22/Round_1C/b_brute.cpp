/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif




void solve(int _TC) {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ab = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            ab += a[i] * a[j];
        }
    }
    ll s = accumulate(a.begin(), a.end(), 0ll);
    if(!ab && s) {
        cout << "Case #" << _TC << ": 0\n";
        return;
    }
    if(!s && !ab) {
        cout << "Case #" << _TC << ": 1\n";
        return;
    }
    if(!s) {
        cout << "Case #" << _TC << ": IMPOSSIBLE\n";
        return;
    }
    ab /= 2;
    dbg(ab, s);
    if((ab / s) * s == ab) {
        cout << "Case #" << _TC << ": ";
        cout << -ab / s << '\n';
        return;
    }
    cout << "Case #" << _TC << ": IMPOSSIBLE\n";
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    for (int TC = 1; TC <= TT; TC++) {
        solve(TC);
    }

    return 0;
}