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

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }



void solve() {
    int n; cin >> n;
    vector<ll> a(n), b(n);
    for (auto &u : a) {
        cin >> u;
    }
    for (auto &u : b) {
        cin >> u;
    }

    // case 1 4 conn
    ll res = 0, curr = 1e9;
    for (int i = 0; i < n; i++) {
        ckmin(curr, abs(a[i] - b[0]));
    }
    res += curr; curr = 1e9;
    for (int i = 0; i < n; i++) {
        ckmin(curr, abs(a[i] - b[n - 1]));
    }
    res += curr; curr = 1e9;
    for (int i = 0; i < n; i++) {
        ckmin(curr, abs(b[i] - a[n - 1]));
    }
    res += curr; curr = 1e9;
    for (int i = 0; i < n; i++) {
        ckmin(curr, abs(b[i] - a[0]));
    }
    res += curr;

    // case 2 3 connec
    ll res21l = abs(a[0] - b[0]); curr = 1e9;
    for (int i = 0; i < n; i++) {
        ckmin(curr, abs(b[i] - a[n - 1]));
    }
    res21l += curr; curr = 1e9;
    for (int i = 0; i < n; i++) {
        ckmin(curr, abs(a[i] - b[n - 1]));
    }
    res21l += curr;

    ll res21r = abs(a[n-1] - b[n-1]); curr = 1e9;
    for (int i = 0; i < n; i++) {
        ckmin(curr, abs(b[i] - a[0]));
    }
    res21r += curr; curr = 1e9;
    for (int i = 0; i < n; i++) {
        ckmin(curr, abs(a[i] - b[0]));
    }
    res21r += curr;

    ll res2xr = abs(a[n-1] - b[0]); curr = 1e9;
    for (int i = 0; i < n; i++) {
        ckmin(curr, abs(b[i] - a[0]));
    }
    res2xr += curr; curr = 1e9;
    for (int i = 0; i < n; i++) {
        ckmin(curr, abs(a[i] - b[n-1]));
    }
    res2xr += curr;

    ll res2xl = abs(a[0] - b[n-1]); curr = 1e9;
    for (int i = 0; i < n; i++) {
        ckmin(curr, abs(b[i] - a[n-1]));
    }
    res2xl += curr; curr = 1e9;
    for (int i = 0; i < n; i++) {
        ckmin(curr, abs(a[i] - b[0]));
    }
    res2xl += curr;

    // case 3 2 conn

    ll res31 = abs(a[0]-b[0]) + abs(a[n-1]-b[n-1]);
    ll res32 = abs(a[0]-b[n-1]) + abs(a[n-1]-b[0]);



    cout << min({res, res31, res32, res2xl, res2xr, res21l, res21r}) << '\n';
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}