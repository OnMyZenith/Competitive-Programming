/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
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

#ifdef asr_debug
#include "dbg.hpp"
const int N = 20;
#else
const int N = 2007;
#define dbg(...) 007
#endif

array<int, 2> q[N];
int g[N][N];
// int best[N];
int curr[N];

// works in 1950ms... hehe
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < m; i++) cin >> q[i][0] >> q[i][1], --q[i][0], --q[i][1];

    for (int i = 0; i < n - k + 1; i++) {
        int e = i + k - 1;
        for (int j = 0; j < m; j++) {
            auto &[l, r] = q[j];
            if(r < i || l > e) continue;
            g[i][j] = min({e - l + 1, r - i + 1, r - l + 1, e - i + 1});
        }
    }

    int mx = 0, c = 0;
    for (int i = 0; i < n - k + 1; i++) {
        for (int j = i; j < n - k + 1; j++) {
            for (int l = 0; l < m; l++) {
                curr[l] = max(g[i][l], g[j][l]);
            }
            c = accumulate(curr, curr + m, 0);
            if(mx < c) {
                mx = c;
            }
        }
    }
    cout << mx << '\n';

    return 0;
}