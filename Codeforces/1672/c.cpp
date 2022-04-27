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
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // auto ans = [&](int i, int j) -> int {
    //     int l = i + j + 1;
    //     if(l <= 2) return 0;
    //     if(l == 3) return 1;
    //     // if(l == 4) return 1;
    //     return l / 2;
    // };
    int f= -1, l = -1;
    for (int i = 0; i < n - 1; i++) {
        if(a[i] == a[i + 1]) {
            f = i; break;
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        if(a[i] == a[i - 1]) {
            l = i; break;
        }
    }
    if(f == -1) {
        cout << "0\n"; return;
    }
    int l_ = l - f + 1;
    cout << (l_ <= 2 ? 0 : max(l_ - 3, 1)) << '\n';
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