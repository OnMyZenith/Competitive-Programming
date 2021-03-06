/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) ((int)v.size())

using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#define chk(...) 007
#endif

const long double PI = 3.14159265358979323846L;
const long long LINF = 2e18L + 007;
const int IINF = 2e9 + 007;
const int MOD = 1e9 + 007; // 998244353;
const int __ = 1e6 + 007;  // 1e6 + 007 => int arr =   4 MB, ll arr =   8 MB
const int _ = 2e5 + 007;   // 2e5 + 007 => int arr = 0.8 MB, ll arr = 1.6 MB

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }


void solve() {
    int n, W; cin >> n >> W;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    
    int MX = accumulate(all(v),0);
    vector<int> dp(MX+1, W + 1);
    dp[0] = 0;
    // dp[i] -> min cost to achieve value of i

    int curr = 0;
    for (int i = 0; i < n; i++) {
        int c = w[i], r = v[i];

        for (int val_already = min(MX - r, curr); val_already >= 0; val_already--) {
            if(dp[val_already] + c <= W) ckmin(dp[val_already + r], dp[val_already] + c);
        }
        curr += r;
    }
    int ans = 0;
    for (int i = 0; i <= MX; i++) {
        if(dp[i] <= W) ans = i;
    }
    cout << ans << '\n';
}

int main() {

#ifdef asr_time
    auto begin = chrono::high_resolution_clock::now();
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(15) << fixed;


    int TT = 1;
    // cin >> TT;
    for (int TC = 1; TC <= TT; TC++) {
        solve();
    }

#ifdef asr_time
    auto end = chrono::high_resolution_clock::now();
    cout << setprecision(2) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count() * 1000 << " ms" << endl;
#endif

    return 0;
}