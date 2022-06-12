/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

void solve() {
    int n, k, z; cin >> n >> k >> z;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    k++;
    ll c1 = accumulate(a.begin(), a.begin() + k, 0LL);
    if(z == 0) {
        cout << c1 << '\n';
        return;
    }
    int idx = -1;
    ll curr = a[0];
    for (int i = 1, best = -2e9 + 7; i < k - 1; i++) {
        if (ckmax(best, a[i] + a[i - 1])) {
            idx = i;
        }
        curr += a[i];
        if (((k - 1 - i) + 1) / 2 <= z) {
            if ((k - 1 - i) & 1) {
                ckmax(c1, (curr + a[i - 1] + (ll)(a[idx] + a[idx - 1]) * (ll)((k - i - 1) / 2)));
            } else {
                ckmax(c1, (curr + (ll)(a[idx] + a[idx - 1]) * (ll)((k - i - 1) / 2)));
            }
        }
    }
    cout << c1 << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}