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

vector<ll> pre(1e5 + 7);



void solve(int _TC) {
    ll a, b; cin >> a >> b;



    cout << "Case #" << _TC << ": ";
    cout << pre[b] - pre[a - 1] << '\n';
}

int main() {
    vamos;


    auto sm = [&](ll c) -> int {
        int res = 0;
        while(c) res += c % 10, c /= 10;
        return res;
    };
    auto product = [&](ll c) -> ll {
        ll res = 1;
        while(c) res *= c % 10, c /= 10;
        return res;
    };
    auto poss = [&](ll i) -> bool {
        return product(i) % sm(i) == 0;
    };
    ll ans = 0;
    for (int i = 1; i <= 1e5; i++) {
        ans += poss(i);
        pre[i] = ans;
    }


    int TT = 1;
    cin >> TT;
    for (int TC = 1; TC <= TT; TC++) {
        solve(TC);
    }

    return 0;
}