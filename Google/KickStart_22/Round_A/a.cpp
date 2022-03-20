/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif




void solve(int _TC) {
    string s, p; cin >> s >> p;
    int i = 0, j = 0, n = (int)s.size(), m = (int)p.size(), ans = 0;
    bool f = 1;
    while(i < n && j < m) {
        if(s[i] == p[j]) i++, j++;
        else j++, ans++;
        if(j == m) f = n == i;
        if(i == n) f = 1, ans += m - j;
    }

    cout << "Case #" << _TC << ": " << (f ? to_string(ans) : "IMPOSSIBLE") << '\n';
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    for (int TC = 1; TC <= TT; TC++) {
        solve(TC);
    }

    return 0;
}