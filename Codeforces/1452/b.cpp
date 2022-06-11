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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    array<ll, 2> need;
    need[0] = (ll)(n - 1) * a[1] - (sum);
    need[1] = (ll)(n - 1) * a[0] - (sum);

    // dbg(need);
    for (int i : {0, 1}) {
        if(need[i] < 0) {
            need[i] %= n - 1;
            if(need[i] < 0) need[i] += n - 1;
        }
    }

    // dbg(need);
    cout << max(need[0], need[1]) << '\n';
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