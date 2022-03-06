/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

template <class T> bool ckmin(T &x, const T y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T y) { return (y > x) ? (x = y, 1) : 0; }

void solve() {
    ll a, b;
    cin >> a >> b;
    if (a >= b) {
        cout << a - b << '\n';
    } else if (b == (a | b)) {
        cout << "1\n";
    } else if (b == a + 1) {
        cout << "1\n";
    } else if (b == ((a + 1) | b)) {
        cout << "2\n";
    } else if (a + 2 == b) {
        cout << "2\n";
    } else if (b - 1 == (a | (b - 1))) {
        cout << "2\n";
    } else if (b + 1 == (a | (b + 1))) {
        cout << "2\n";
    } else
        cout << "3\n";
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    while (TT--) {
        solve();
    }

    return 0;
}