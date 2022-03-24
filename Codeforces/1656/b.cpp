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
    vector<ll> a(n);
    for (auto &u : a) {
        cin >> u;
    }
    sort(a.begin(), a.end());
    set<ll> s(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) {
        if(s.count(a[i] + k)) {
            cout << "YES\n";
            return;
        }
    }
    // if(n & 1) {
    //     for (int i = 0; i < n; i++) {
    //         a[i] -= a[0];
    //     }
    //     for (int i = 1; i < n - 1; i++) {
    //         if(a[n - 1] - a[i] == k) {
    //             cout << "YES\n";
    //             return;
    //         }
    //     }
    // } else {
        // for (int i = 0; i < n - 1; i++) {
        //     if(a[n - 1] - a[i] == k) {
        //         cout << "YES\n";
        //         return;
        //     }
        // }
    // }

    cout << "NO" << '\n';
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