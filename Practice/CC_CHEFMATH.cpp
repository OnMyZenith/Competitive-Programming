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
#else
#define dbg(...) 007
#endif

const int MOD = 1e9 + 7;
vector<int> f;

int calc(int need, int from, int start) {
    if (from == 0) return need == 0;
    if (need <= 0) return 0;
    if ((ll)f[start] * from < need) return 0;

    int ans = calc(need - f[start], from - 1, start);

    if (start > 0 && (ll)f[start - 1] * from >= need) {
        ans += calc(need, from, start - 1);
    }

    return ans;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    f = {1, 2};
    for (int i = 0; f.back() + *++f.rbegin() < MOD; i++) {
        f.push_back(f.back() + *++f.rbegin());
    }

    int TT = 1;
    cin >> TT;
    while(TT--) {
        int x, k; cin >> x >> k;
        cout << calc(x, k, 42) << '\n';
    }

    return 0;
}
