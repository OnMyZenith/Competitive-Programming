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



void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto &u : a) {
        cin >> u;
    }
    int MX = *max_element(a.begin(), a.end());
    int ans = lt(0, MX, [&](int m){
        int cnt = 0;
        for (int i = 0; i < n; i++) cnt += a[i] < m;
        return cnt <= k;
    });
    cout << ans << '\n';



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