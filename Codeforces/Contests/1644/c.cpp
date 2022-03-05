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
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> sum_seg(n + 1, -1e9), pre(n + 1);
    sum_seg[0] = 0;
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];

    for (int seg_size = 1; seg_size <= n; seg_size++) {
        for (int j = 0; j + seg_size <= n; j++) {
            ckmax(sum_seg[seg_size], pre[j + seg_size] - pre[j]);
        }
    }
    for (int k = 0; k <= n; k++) {
        int best = 0;
        for (int seg_size = 1; seg_size <= n; seg_size++) 
            ckmax(best, sum_seg[seg_size] + min(seg_size, k) * x);
        cout << best << " \n"[k == n];
    }
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