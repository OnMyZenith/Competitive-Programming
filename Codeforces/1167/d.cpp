/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

// Check result <= hi
template <class T, class U> T ft(T lo, T hi, U f) {
    ++hi, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo) / 2;
        f(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n; string s; cin >> n >> s;

    int best = ft(1, n, [&](int x) -> bool {
        for (int i = 0, cntr = 0, cntb = 0; i < n; i++) {
            if (s[i] == '(') {
                if (cntr < x) cntr++;
                else cntb++;
            } else {
                if (cntr) cntr--;
                else cntb--;
            }
            if (cntb > x) return false;
        }
        return true;
    });

    for (int i = 0, cntr = 0, cntb = 0; i < n; i++) {
        if (s[i] == '(') {
            if (cntr < best) cntr++, cout << 0;
            else cntb++, cout << 1;
        } else {
            if (cntr) cntr--, cout << 0;
            else cntb--, cout << 1;
        }
    }
    dbg(best);
    cout << '\n';


    return 0;
}