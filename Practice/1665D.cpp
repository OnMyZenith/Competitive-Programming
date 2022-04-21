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
    auto q = [](int a, int b) -> int {
        cout << "? " << a << " " << b << endl;
        int c; cin >> c; return c;
    };
    int curr = 0;
    for (int i = 0; i < 30; i++) {
        int bit = 1 << i;
        int res = q(bit - curr, bit * 3 - curr);
        if(__builtin_ctz(res) > i) {
            curr |= bit;
        }
    }
    cout << "! " << curr << '\n';
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