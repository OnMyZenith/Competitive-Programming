/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int, int>> good = {{0, -1}};
    for (int i = 0; i < n - 1; i++) {
        if(a[i] >= a[i + 1] * 2) {
            good.back().second = i;
            good.push_back({i + 1, -1});
        }
        if(i == n - 2) {
            good.back().second = n - 1;
        }
    }
    int ans = 0;
    for (auto &[x, y] : good) {
        ans += max(0, y - x + 1 - (k + 1) + 1);
    }
    cout << ans << '\n';



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