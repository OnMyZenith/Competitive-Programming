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
    int n, r, b; cin >> n >> r >> b;
    int f = r / (b + 1);
    int e = r % (b + 1);
    int t = b + 1;
    string res;
    // for (int i = 0; i < n; i++) {
    //     res += 
    // }
    for (int i = 0; i < t - e; i++) {
        res += string(f, 'R');
        res += 'B';
    }
    for (int i = 0; i < e; i++) {
        res += string(f + 1, 'R');
        res += 'B';
    }
    res.pop_back();
    cout << res << '\n';

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