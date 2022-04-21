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


// Check result >= lo
template <class T, class U> T lt(T lo, T hi, U f) {
    --lo, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo + 1) / 2;
        f(mid) ? lo = mid : hi = mid - 1;
    }
    return lo;
}

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<ll> pre(n), suff(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i] = (i ? pre[i - 1] : 0) + a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = (i < n - 1 ? suff[i + 1] : 0) + a[i];
    }
    int best = 0;
    for (int i = 0; i < n; i++) {
        int tar = pre[i];
        int j = lt(0, n - 1, [&](int k) -> bool {
            return suff[k] >= tar;
        });
        if(j > i && suff[j] == tar) {
            ckmax(best, i + 1 + (n - j));
        }
    }
    cout << best << '\n';



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