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
    long double x, y; cin >> x >> y;
    if(!x && !y) {
        cout << "0\n";
        return;
    }
    if((ll)sqrt(x * x + y * y) * (ll)sqrt(x * x + y * y) == x * x + y * y) {
        cout << "1\n";
    } else {
        cout << "2\n";
    }



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