/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

void solve() {
    string s; cin >> s;
    int curr = 0;

    ll extra = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        curr += s[i] == '+' ? 1 : -1;
        if (curr < 0) {
            extra += i + 1;
            curr = 0;
        }
    }
    cout << extra + (ll)s.size() << '\n';
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