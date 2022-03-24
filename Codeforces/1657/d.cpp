/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
#ifndef asr_debug
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("Ofast")
// Can casuse floating point errors, assumes associativeness for instance

#pragma GCC target("avx2")
#pragma GCC target("popcnt,lzcnt,bmi,bmi2,tune=native")
// #pragma GCC target("avx,fma")
// #pragma GCC target("sse4.2,fma")
// run custom tests with stuff like assert(__builtin_cpu_supports("avx2"))
// or use avx instead of sse4.2, leave fma in as it was covered in avx2
#endif

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif



template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

// Check result against SIZE of vector
template <class T> int lwbf(vector<T> &a, const T &b) { return int(lower_bound(a.begin(), a.end(), b) - begin(a)); }
// Check result against SIZE of vector
template <class T> int upbf(vector<T> &a, const T &b) { return int(upper_bound(a.begin(), a.end(), b) - begin(a)); }



int main() {
    vamos;

    ll n, K; cin >> n >> K;
    vector<ll> c(n), v(n), dp(K + 1), best(K + 1);
    for (int i = 0; i < n; i++) {
        ll d, h;
        cin >> c[i] >> d >> h;
        v[i] = d * h;
        ckmax(dp[c[i]], v[i]);
    }
    dbg(dp);

    for (int cost = 1; cost <= K; cost++) {
        if(dp[cost]) {
            int cnt = 2;
            while(cost * cnt <= K) {
                ckmax(dp[cnt * cost], cnt * dp[cost]);
                cnt++;
            }
        }
    }

    for (int i = 1; i <= K; i++) ckmax(dp[i], dp[i - 1]);

    ll m; cin >> m;
    vector<ll> M(m);
    for (int i = 0; i < m; i++) {
        ll d, h;
        cin >> d >> h;
        M[i] = d * h;
    }

    dbg(dp);
    dbg(M);
    for (int i = 0; i < m; i++) {
        ll need = upbf(dp, M[i]);
        cout << (need <= K ? need : -1) << " \n"[i == m - 1];
    }

    return 0;
}