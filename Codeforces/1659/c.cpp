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
    ll n, a, b; cin >> n >> a >> b;
    vector<ll> x(n);
    ll cost = 0;
    for (auto &u : x) {
        cin >> u;
        cost += u * b;
    }

    for (int i = 0; i < n; i++) {
        ll ahead = n - i - 1;
        if(ahead * (x[i] - (i ? x[i - 1] : 0)) * b > (x[i] - (i ? x[i - 1] : 0)) * a) {
            cost -= ahead * (x[i] - (i ? x[i - 1] : 0)) * b - (x[i] - (i ? x[i - 1] : 0)) * a;
        } else break;
    }

    cout << cost << '\n';



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