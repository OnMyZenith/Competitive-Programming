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
    string s; char c; cin >> s >> c;
    int n = (int)s.size();
    bool f = 0;
    for (int i = 0; i < n; i++) {
        if(s[i] == c) {
            f |= (i % 2 == 0) && ((n - i - 1) % 2 == 0);
        }
    }
    
    cout << (f ? "YES" : "NO") << '\n';


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