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
    int n; string s; cin >> n >> s;
    int ones = (int)count(s.begin(), s.end(), '1');
    int zeros = n - ones;
    if (s.front() != s.back() || s.front() != '1' || (zeros & 1)) {
        cout << "NO\n";
        return;
    }
    string z1, z2;
    for (int i = 0; i < zeros; i++) {
        if (i & 1) z1 += '(', z2 += ')';
        else z2 += '(', z1 += ')';
    }
    string o;
    for (int i = 0; i < ones; i++) {
        o += (i >= ones / 2 ? ')' : '(');
    }
    string r1, r2;
    for (int i = 0, j = 0, k = 0; k < n; k++) {
        if (s[k] == '1') {
            r1 += o[i];
            r2 += o[i];
            i++;
        } else {
            r1 += z1[j];
            r2 += z2[j];
            j++;
        }
    }
    cout << "YES\n";
    cout << r1 << '\n';
    cout << r2 << '\n';
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