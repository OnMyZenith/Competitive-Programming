/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


void solve() {
    int n; cin >> n;
    ll s; cin >> s;
    vector<array<int, 2>> toys(n);
    vector<int> u_lim;
    for (int i = 0; i < n; i++) {
        cin >> toys[i][0] >> toys[i][1];
        u_lim.push_back(toys[i][1]);
    }
    // ll s; cin >> s;
    sort(u_lim.begin(), u_lim.end());
    dbg(u_lim);
    int lo = 0, hi = u_lim[n / 2];
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        ll need = 0;
        // ll need = (ll)mid * (n / 2 + 1);
        vector<int> l_lim;
        int cnt = n / 2;
        for (int i = 0; i < n; i++) {
            if (toys[i][1] < mid) need += toys[i][0], cnt--;
            else {
                l_lim.push_back(toys[i][0]);
            }
        }
        sort(l_lim.begin(), l_lim.end());
        dbg(need, cnt, s, mid, l_lim);
        assert((int)l_lim.size() == cnt + n / 2 + 1);
        need += accumulate(l_lim.begin(), l_lim.begin() + cnt, 0ll);
        for (int i = cnt; i < (int)l_lim.size(); i++) {
            need += max(mid, l_lim[i]);
        }
        if (need <= s) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}