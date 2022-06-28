/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n; cin >> n;
    string s; cin >> s;
    n -= 11;
    n /= 2;
    int cnt = 0;
    for (int i = 0, l = -1; i <= 2 * n; i++) {
        cnt += s[i] == '8';
    }

    if (cnt > n) {
        cout << "YES\n";
    } else cout << "NO\n";

    return 0;
}