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
    vector<int> v(n);
    for (auto &u : v) {
        cin >> u;
    }
    if(count(v.begin(), v.end(), 0) == n) {
        cout << "0\n";
        return;
    }

    // sort(v.begin(), v.end());
    // int curr = 1;
    // for (int i = 0; i < n - 1; i++) {
    //     curr = max(curr, max(v[i + 1] - v[i] - 1, 0));
    // }
    // cout << curr << '\n';

    sort(v.rbegin(), v.rend());
    ll sum = accumulate(v.begin() + 1, v.end(), 0LL);
    // if(a[0] - 1 > sum) {
    // }
    cout << max(v[0] - sum, 1LL) << '\n';
    // ll a = 0, b = 0;
    // for (int i = 0; i < n; i++) {
    //     if(a > b) b += v[i];
    //     else a += v[i];
    // }
    // cout << max(abs(a - b), 1LL) << '\n';
    // dbg(a, b);
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