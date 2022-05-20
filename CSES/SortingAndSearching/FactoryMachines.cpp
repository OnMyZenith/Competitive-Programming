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


int main() {
    vamos;

    ll n, t; cin >> n >> t;
    vector<ll> a(n);
    for (auto &i : a) cin >> i;

    auto timeEnough = [&](ll x) -> bool {
        ll _made = 0;
        for (auto &req : a) {
            _made += x / req;
            if(_made >= t) return true;
        }
        return false;
    };

    ll lo = 0, hi = 4e18;

    while(lo < hi) {
        ll mid = (lo + hi) / 2;
        if(timeEnough(mid)) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << '\n';

    return 0;
}