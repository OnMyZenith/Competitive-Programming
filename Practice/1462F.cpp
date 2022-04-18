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
    vector<pair<int, int>> a(n);
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        a[i] = {l[i], r[i]};
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    int best = 1e9;
    for (int i = 0; i < n; i++) {
        auto [_l, _r] = a[i];
        int curr = n - int(upper_bound(l.begin(), l.end(), _r) - l.begin()) + int(lower_bound(r.begin(), r.end(), _l) - r.begin());
        ckmin(best, curr);
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