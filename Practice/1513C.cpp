/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
const int MX = 20;
#else
const int MX = 2e5 + 15;
#define dbg(...) 007
#endif

const int MOD = 1e9 + 7;

int main() {
    vamos;

    vector<vector<int>> f(MX, vector<int>(10));
    f[0][0] = 1;
    for (int _ = 1, i = 0; _ < MX; _++) {
        f[_][1] = f[_ - 1][9];
        for (int k = 0; k < 10; k++) {
            f[_][k] += (k ? f[_ - 1][k - 1] : f[_ - 1][9]);
        }
        if(f[_][1] >= MOD) f[_][1] -= MOD;
    }
    int TT = 1;
    cin >> TT;
    while (TT--) {
        int n, m; cin >> n >> m;
        vector<int> fr(10);
        while (n) fr[n % 10]++, n /= 10;
        int cnt = 0;
        for (int i = 0; i < 10; i++) {
            cnt += (ll) fr[i] * (accumulate(f[m + i].begin(), f[m + i].end(), 0ll)) % MOD;
            cnt %= MOD;
        }
        cout << cnt << '\n';
    }

    return 0;
}