/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

const int inf = 1e9;
template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = (int)a.size();
    vector<int> min_coins(x + 1, inf);
    min_coins[0] = 0;

    // min_coins[i][tot_val] = min_coins[i - 1][tot_val - this_coin] + 1;

    for (int i = 1; i <= n; i++) {
        int val = a[i - 1];
        // for (int tot_val = x; tot_val - val >= 0; tot_val--) {
        for (int tot_val = val; tot_val <= x; tot_val++) {
            ckmin(min_coins[tot_val], min_coins[tot_val - val] + 1);
        }
    }
    cout << (min_coins[x] == inf ? -1 : min_coins[x]) << '\n';
    return 0;
}
