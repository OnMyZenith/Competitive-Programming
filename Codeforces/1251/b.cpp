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
    string s;
    bool golden = 0;
    int ones = 0, zeros = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        ones += count(s.begin(), s.end(), '1');
        zeros += (int)s.size();
        golden |= (int)s.size() & 1;
    }
    zeros -= ones;
    cout << n - (((zeros & 1) || (ones & 1)) && !golden) << '\n';
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