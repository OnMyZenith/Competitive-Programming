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
    int cntq = 0;
    auto q = [&](int l, int r) -> bool {
        cout << "? " << l << " " << r << endl;
        assert (++cntq <= 15);
        int cnt = 0;
        for (int i = 0, x; i < r - l + 1; i++) {
            cin >> x;
            cnt += x <= r && x >= l;
        }
        return cnt & 1;
    };
    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = (hi + lo) / 2;
        if (q(lo, mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << "! " << lo << endl;
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