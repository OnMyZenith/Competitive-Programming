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




void solve() {
    string s; cin >> s;
    int n = (int)s.size();
    ll sc = 0;
    for (int i = 0; i < n; i++) sc += s[i] - 'a' + 1;
    ll a = 0, b = 0;
    if(n & 1) {
        b = (s.front() > s.back() ? s.back() - 'a' + 1 : s.front() - 'a' + 1);
        a = sc - b;
    } else a = sc;
    cout << (a > b ? "Alice " : "Bob " ) << abs(a - b) << '\n';


}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}