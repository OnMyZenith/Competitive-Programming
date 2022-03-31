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

bitset<300007> vis;

void solve() {
    int l, r; cin >> l >> r;
    int n = r - l + 1;
    vector<int> a(n);
    for (auto &u : a) {
        cin >> u;
    }
    int ans = 0;
    vector<int> poss;
    for (int j = 17; j >= 0; j--) {
        int cnt = 0;
        for (int i = l; i <= r; i++) {
            cnt += (i >> j) & 1;
        }
        int f = 0;
        for (int i = 0; i < n; i++) {
            f += (a[i] >> j) & 1;
        }
        if(f != cnt) ans |= (1 << j);
        else poss.push_back(1 << j);
    }

    int m = (int)poss.size();
    reverse(poss.begin(), poss.end());
    for (int mask = 0; mask < (1 << m); mask++) {
        int new_ans = ans;
        for (int j = 0; j < m; j++) {
            if((mask >> j) & 1) {
                new_ans |= poss[j];
            }
        }
        bool p = 1;
        set<int> s;
        for (int i = 0; i < n; i++) {
            int x = a[i] ^ new_ans;
            if(x > r || x < l || s.count(x)) {
                p = 0; break;
            } else {
                s.insert(x);
            }
        }
        if(p) {
            cout << new_ans << '\n';
            return;
        }
    }
    assert(false);
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}