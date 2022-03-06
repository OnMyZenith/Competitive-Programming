/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ld = long double;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

vector<pair<ld, int>> res;

void f(ld c, ld m, ld p, ld v, ld prob_of_this, int cnt) {
    if(c) {
        ld new_c = max(c - v, 0.0L);
        ld drop = min(c, v);
        if(m > 1e-7) {
            // dbg(m);
            f(new_c, m + drop / 2, p + drop / 2, v, prob_of_this * c, cnt + 1);
        } else {
            f(new_c, m, p + drop, v, prob_of_this * c, cnt + 1);
        }
    }
    if(m) {
        ld new_m = max(m - v, 0.0L);
        ld drop = min(m, v);
        if(c > 1e-7) {
            // dbg(c);
            f(c + drop / 2, new_m, p + drop / 2, v, prob_of_this * m, cnt + 1);
        } else {
            f(c, new_m, p + drop, v, prob_of_this * m, cnt + 1);
        }
    }
    res.emplace_back(prob_of_this * p, cnt + 1);
}

void solve() {
    ld c, m, p, v; res.clear();
    cin >> c >> m >> p >> v;
    f(c, m, p, v, 1, 0);
    ld ans = 0;
    for (auto &[prob, turns] : res) {
        ans += turns * prob;
    }
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