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


// Check result <= hi
template <class T, class U> T ft(T lo, T hi, U f) {
    ++hi, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo) / 2;
        f(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int tar = *max_element(a.begin(), a.end());
    cout << min(ft(0ll, (ll)2e18, [&](ll x) -> bool {
        ll ol = (x + 1) / 2, el = x / 2;
        for (int i = 0; i < n; i++) {
            ll need = (tar - a[i]);
            if(2 * el >= need) {
                el -= need / 2;
                need = need & 1;
            } else {
                need -= 2 * el;
                el = 0;
            }
            if(need) {
                if(ol >= need) ol -= need, need = 0;
                else return false;
            }
        }
        return true;
    }), ft(0ll, (ll)2e18, [&](ll x) -> bool {
        ll ol = (x + 1) / 2, el = x / 2;
        for (int i = 0; i < n; i++) {
            ll need = (tar + 1 - a[i]);
            if(2 * el >= need) {
                el -= need / 2;
                need = need & 1;
            } else {
                need -= 2 * el;
                el = 0;
            }
            if(need) {
                if(ol >= need) ol -= need, need = 0;
                else return false;
            }
        }
        return true;
    })) << '\n';
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