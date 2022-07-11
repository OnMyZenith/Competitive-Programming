/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
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
#else
#define dbg(...) 007
#endif

const int MOD = 1e9 + 007; // 998244353;

// Z[i] is the length of the longest string that is, a prefix of s and a prefix of the suffix of s starting at i.
vector<int> z_function(const string &s) {
    int n = (int)s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) z[i] = min(z[i - l], r - i + 1);

        while (z[i] + i < n && s[z[i] + i] == s[z[i]])
            z[i]++;

        if (i + z[i] - 1 > r) r = i + z[i] - 1, l = i;
    }
    return z;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    string s;
    int k;
    cin >> s >> k;
    int n = (int)s.size();
    vector<vector<int>> adj(n);

    for (int i = 0; i < k; i++) {
        string str; cin >> str;
        int m = (int)str.size();
        auto v = z_function(str + '$' + s);
        for (int j = m + 1; j < m + 1 + n; j++) {
            if (v[j] == m) adj[j - (m + 1) + m - 1].push_back(m);
        }
    }

    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) 
        for (auto &len : adj[i - 1])
            if (i >= len) {
                dp[i] += dp[i - len];
                if (dp[i] >= MOD) dp[i] -= MOD;
            }

    dbg(adj);
    dbg(dp);
    cout << dp[n] << '\n';

    return 0;
}
