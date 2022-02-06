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
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    ll XR = 0;
    for (auto &u : a) {
        cin >> u;
        XR+=u;
    }
    // dbg(XR);
    if(!(((XR&1)^(x&1))^(y&1))) cout << "Alice\n";
    else cout <<"Bob\n";

}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    for (int TC = 1; TC <= TT; TC++) {
        solve();
    }

    return 0;
}