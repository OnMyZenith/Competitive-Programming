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
    int n, k; cin >> n >> k; n++;
    bool a = n % 3 != 1;
    if (n <= k) {
        cout << (a ? "Alice" : "Bob") << '\n';
        return;
    }
    n -= k;
    if (k % 3 == 1) {
        if (n <= 2) {
            cout << "Alice\n";
        } else {
            n -= 2;
            cout << ((n % 3 != 1) ? "Alice" : "Bob") << '\n';
        }
        return;
    }
    if (n == 1) {
        cout << "Alice\n";
    } else {
        n--;
        n %= k + 1;
        cout << ((n % 3 != 1) ? "Alice" : "Bob") << '\n';
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