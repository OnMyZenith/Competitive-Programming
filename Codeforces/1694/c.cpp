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
    vector<ll> a(n), pre(n + 1), suff(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i], pre[i + 1] = pre[i] + a[i];

    for (int i = n - 1; i >= 0; i--) {
        suff[i] = suff[i + 1] + a[i];
    }
    if(count(a.begin(), a.end(), 0) == n) {
        cout << "Yes\n";
        return;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i]) {
            n = i + 1;
            break;
        }
    }

    bool pass = pre[n] == 0;
    // dbg(pre, suff);
    for (int i = 1; i < n; i++) {
        dbg(suff[i], pre[i]);
        pass &= (pre[i] + suff[i] == 0) && (suff[i] < pre[i]);
    }



    // ll carry = 0;
    // // bool f = 1;
    // for (int i = n - 1; i >= 0; i--) {
    //     a[i] += carry;
    //     carry += a[i] - carry;
    // }
    // // dbg(f);
    // dbg(a);
    cout << (!pass ? "No" : "Yes") << '\n';
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