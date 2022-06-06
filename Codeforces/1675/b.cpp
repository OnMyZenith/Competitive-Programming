/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &u : a) {
        cin >> u;
    }
    reverse(a.begin(), a.end());

    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        while(a[i] <= a[i + 1]) {
            if(!a[i + 1]) {
                cout << "-1\n";
                return;
            }
            a[i + 1] /= 2;
            cnt++;
        }
    }
    cout << cnt << '\n';




}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}