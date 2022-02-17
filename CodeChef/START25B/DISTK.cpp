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
ll n, k;
ll v(ll m){
    return (m*(m+1)/2) + (n-m);
}
bool f(ll m){
    ll u = v(m);
    return u>=k;
}
void solve() {
    cin >> n>> k;
    ll x = ft(1LL, n, f);
    ll kill = v(x) - k;
    ll y = (kill);
    if(kill) x--;
    if(!kill) y = x;
    for (ll i = 1; i <= n ; i++) {
        if(i <= x) cout << i << " \n"[i==n];
        else {
            cout << y << " \n"[i==n];
        }
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