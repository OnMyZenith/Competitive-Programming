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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    ll cost = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cost += a[i];
        a[i] -= (n - i);
    }
    sort(a.rbegin(), a.rend());

    for (int i = 0; i < k; i++) {
        cost -= a[i];
        cost -= i + 1;
    }
    cout << cost << '\n';



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