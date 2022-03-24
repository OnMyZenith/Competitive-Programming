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




void solve() {
    ll n; cin >> n;
    ll sq = ceil(sqrt((long double)n));
    ll lo = 0, hi = sq;
    while(hi >= lo) {
        ll mid = (lo + hi) / 2;
        if(n / mid == (n % mid)) {
            cout << (n % mid) << '\n';
            return;
        } else if(n / mid > (n % mid)) lo = mid + 1;
        else hi = mid - 1;
        dbg(mid);
        dbg(n / mid, (n % mid));
        dbg(lo, hi);
    }
    cout << -1 << '\n';


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