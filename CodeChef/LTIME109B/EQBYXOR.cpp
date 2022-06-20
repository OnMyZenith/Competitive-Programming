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
    int a, b, n;
    cin >> a >> b >> n;
    if (a == b) {
        cout << "0\n";
        return;
    }
    vector<int> x;
    for (int i = 0; i < 31; i++) {
        if (((a >> i) & 1) != ((b >> i) & 1)) {
            x.push_back(1 << i);
        }
    }
    if (x.back() >= n) {
        cout << "-1\n";
    } else {
        cout << (accumulate(x.begin(), x.end(), 0) >= n ? 2 : 1) << '\n';
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