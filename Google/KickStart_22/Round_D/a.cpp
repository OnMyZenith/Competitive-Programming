/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

using ld = long double;
void solve(int _TC) {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    ll ans = accumulate(a.begin() + n - m + 1, a.end(), 0ll);
    ld a1 = 0;
    if ((n - m + 1) & 1) {
        a1 = a[(n - m + 1) / 2];
    } else {
        a1 = a[(n - m - 1) / 2] + a[(n - m - 1) / 2 + 1];
        a1 /= 2;
    }


    cout << "Case #" << _TC << ": ";
    cout << (ld)a1 + ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    for (int TC = 1; TC <= TT; TC++) {
        solve(TC);
    }

    return 0;
}