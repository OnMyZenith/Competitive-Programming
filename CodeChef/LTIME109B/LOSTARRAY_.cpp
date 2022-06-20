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
    vector<int> a(n + 1);
    int x = 0;
    for (int i = 0; i < n + 1; i++) cin >> a[i], x ^= a[i];

    if (n & 1) {
        for (int i = 0; i < n + 1; i++) {
            if(x == a[i]) {
                for (int j = 0, cnt = n; j < n + 1; j++) {
                    if (j == i) continue;
                    cout << (a[j] ^ x) << " \n"[--cnt == 0];
                }
                return;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        a[i + 1] ^= a[0];
    }
    x = 0;
    for (int i = 0; i < n; i++) x ^= a[i + 1];

    for (int i = 0; i < n; i++) cout << a[i + 1] << " \n"[i == n - 1];
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