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
    int n;
    string a, b;
    cin >> n >> a >> b;
    // if (n == 2) {
    //     if (a == b || (count(b.begin(), b.end(), '1') == 0 || count(b.begin(), b.end(), '1') == 2)) {
    //         cout << "YES\n";
    //         return;
    //     } 
    //     cout << "NO\n";
    //     return;
    // }

    bool poss = 0;
    for (int i = 0; i < n;) {
        if (b[i] == '1') {
            i++;
            continue;
        }
        int cnt = 0;
        for (int j = i; j < n && b[j] == '0'; j++, cnt++);
        poss |= cnt >= 2;
        i += cnt;
    }

    for (int i = 0; i < n;) {
        if (b[i] == '0') {
            i++;
            continue;
        }
        int cnt = 0;
        for (int j = i; j < n && b[j] == '1'; j++, cnt++);
        poss |= cnt >= 2;
        i += cnt;
    }

    cout << (a == b || (count(a.begin(), a.end(), '1') && (poss || count(b.begin(), b.end(), '1') == 0)) ? "YES" : "NO") << '\n';
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
