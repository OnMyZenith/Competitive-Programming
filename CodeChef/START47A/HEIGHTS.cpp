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
    map<int, int> cnt;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }
    int diff = 0;
    int mxf = 0;
    for (auto &[h, f] : cnt) {
        if (f == 1) diff++;
        mxf = max(mxf, f);
    }
    if (cnt.rbegin()->second == 1 && diff == 1 && mxf == 2) diff += 2;
    cout << (diff + 1) / 2 << '\n';
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
