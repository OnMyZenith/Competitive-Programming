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


void solve() {
    string s; cin >> s;
    int n = (int)s.size();

    int best = n;
    for (int i = 0; i < 10; i++) {
        char m = char(i + '0');
        int match = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == m) match++;
        }
        best = min(best, n - match);
    }

    for (int i = 1; i < 100; i++) {
        string m = to_string(i);
        if((int)m.size() == 1) m = "0" + m;
        int k = 0; int match = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == m[k]) k ^= 1, match++;
        }
        if(match & 1) match--;
        best = min(best, n - match);
    }
    cout << best << '\n';
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