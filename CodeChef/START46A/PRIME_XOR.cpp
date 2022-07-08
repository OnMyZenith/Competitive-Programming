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
    int x, y, a, b, c; cin >> x >> y;
    assert((x & 1) || (y & 1));
    if (x & 1) {
        a = (x ^ 2);
        if (y & 1) {
            b = y ^ 2;
            c = 2;
        } else {
            b = y ^ a;
            c = 2;
        }
    } else {
        swap(x, y);
        a = (x ^ 2);
        if (y & 1) {
            b = y ^ 2;
            c = 2;
        } else {
            b = y ^ a;
            c = 2;
        }
    }
    vector<int> v = {a, b, c};
    sort(v.begin(), v.end());
    for (int i = 0; i < 3; i++) cout << v[i] << " \n"[i == 2];
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