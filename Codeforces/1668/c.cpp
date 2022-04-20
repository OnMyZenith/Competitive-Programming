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

template <class T> T fdivf(T &a, T &b) { return a / b - ((a ^ b) < 0 && a % b); }
template <class T> T cdivf(T &a, T &b) { return a / b + ((a ^ b) > 0 && a % b); }
template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }


int main() {
    vamos;

    ll n; cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    ll best = 4e18, curr = 0;

    for (ll i = 0; i < n; i++) {
        vector<ll> b(n);
        curr = 0;
        for (ll j = i - 1; j >= 0; j--) {
            curr += (b[j + 1] / a[j] + 1);
            b[j] = (b[j + 1] / a[j] + 1) * a[j];
        }
        for (ll j = i + 1; j < n; j++) {
            curr += b[j - 1] / a[j] + 1;
            b[j] = (b[j - 1] / a[j] + 1) * a[j];
        }
        ckmin(best, curr);
    }
    cout << best << '\n';

    return 0;
}