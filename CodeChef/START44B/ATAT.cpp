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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> pre(n + 1), suff(n + 1);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + (n - a[i]);
    for (int i = n - 1; i >= 0; i--) suff[i] = suff[i + 1] + (n - a[i]);
    for (int i = 0; i < n; i++) {
        int lwb = int(lower_bound(a.begin(), a.end(), i) - a.begin());
        int upb = int(upper_bound(a.begin(), a.end(), i) - a.begin());
        int def_occur = n - upb;
        int ambi = lwb;
        // dbg(def_occur, ambi);
        cout << def_occur << " " << def_occur + suff[n - def_occur] + pre[ambi] << '\n';
    }
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