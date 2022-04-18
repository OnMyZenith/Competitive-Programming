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
    int n; cin >> n;
    vector<int> a(n), suff(n), pre(n), tmp(n + 1);
    iota(tmp.begin(), tmp.end(), 0);
    set<int> not_seen(tmp.begin(), tmp.end()), ns; ns = not_seen;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        not_seen.erase(a[i]);
        pre[i] = *not_seen.begin();
    }
    not_seen = ns;
    for (int i = n - 1; i >= 0; i--) {
        not_seen.erase(a[i]);
        suff[i] = *not_seen.begin();
    }


    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            res += pre[j - 1] < a[i] && pre[j - 1] < a[j] && suff[i + 1] < a[j] && suff[i + 1] < a[i];
        }
    }
    cout << res << '\n';





    // not_seen = ns;
    // for (int i = 0; i < n; i++) {
    //     not_seen.erase(suff[i]);
    //     not_seen.erase(pre[i]);
    // }
    // ll cnt = 0;
    // for (int i = 0; i < n; i++) {
    //     cnt += not_seen.count(i);
    // }
    // cout << cnt * (cnt - 1) / 2 << '\n';



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