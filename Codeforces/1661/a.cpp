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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    auto _a = a, _b = b;
    ll ans1 = 0, ans2 = 0;
    for (int i = 1; i < n; i++) {
        if(abs(a[i - 1] - a[i]) + abs(b[i - 1] - b[i]) > abs(a[i - 1] - b[i]) + abs(b[i - 1] - a[i])) swap(a[i], b[i]);
        ans1 += abs(a[i - 1] - a[i]) + abs(b[i - 1] - b[i]);
    }
    a = _a, b = _b;

    swap(a[0], b[0]);
    for (int i = 1; i < n; i++) {
        if(abs(a[i - 1] - a[i]) + abs(b[i - 1] - b[i]) > abs(a[i - 1] - b[i]) + abs(b[i - 1] - a[i])) swap(a[i], b[i]);
        ans2 += abs(a[i - 1] - a[i]) + abs(b[i - 1] - b[i]);
    }
    cout << min(ans1, ans2) << '\n';


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