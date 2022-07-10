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

template <class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template <class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

#include <bits/extc++.h>
using namespace __gnu_pbds;

struct splitmix64_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    size_t operator()(pair<uint64_t, uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^ splitmix64(x.first + 4 * FIXED_RANDOM);
    }
};

template <class T, class U, typename Hash = splitmix64_hash> using hash_map = gp_hash_table<T, U, Hash>;
template <class T, typename Hash = splitmix64_hash> using hash_set = hash_map<T, null_type, Hash>;

template <class T> using pqdec = std::priority_queue<T>;
template <class T> using pqinc = std::priority_queue<T, vector<T>, greater<T>>;

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }


void solve(int _TC) {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int m; cin >> m;
    vector<int> b(m);
    for (auto &e : b) {
        cin >> e;
    }
    a.erase(unique(a.begin(), a.end()), a.end());
    n = (int)a.size();

    // hash_map<int, vector<int>> allB;

    // for (int i = 0; i < m; i++) {
    //     allB[b[i]].push_back(i);
    // }
    // vector<ll> dp_prev(m, 4e18);
    // for (auto &i: allB[a[0]]) {
    //     dp_prev[i] = 0;
    // }
    // for (int i = 1; i < n; i++) {
    //     auto next_vals = allB[a[i]];
    //     auto prev_vals = allB[a[i - 1]];
    //     vector<ll> dp_next(m, 4e18);
    //     for (auto &pos: next_vals) {
    //         for (auto &j : prev_vals) {
    //         // dp_next[pos] = dp_prev[0] + pos;
    //         // for (int j = 1; j < m; j++) {
    //             dp_next[pos] = min(dp_next[pos], dp_prev[j] + abs(j - pos));
    //         }
    //     }
    //     dp_prev = dp_next;
    //     dbg(dp_prev);
    // }

    // pqinc<pair<int, pair<ll, int>>> q;
    // pqinc<pair<ll, pair<int, int>>> q;
    // set<pair<ll, pair<int, int>>> q;
    // vector<vector<ll>> minDis(n, vector<ll>(m, 4e18));

    // for (auto &i: allB[a[0]]) {
    //     // q.push({0, {0, i}});
    //     q.insert({0, {0, i}});
    //     minDis[0][i] = 0;
    // }

    // ll ans = 4e18;
    // while (!q.empty()) {
    //     // auto [idx_A, p] = q.top();
    //     auto [dis, p] = *q.begin();
    //     auto [idx_A, idx_B] = p;
    //     idx_A = -idx_A; q.erase(q.begin());
    //     // idx_A = -idx_A; q.pop();
    //     if (idx_A == n - 1) {
    //         ans = dis;
    //         break;
    //     }
    //     // if (minDis[idx_A][idx_B] < dis) continue;
    //     bool poss = 1;
    //     for (int i = idx_A; i < n && poss; i++) {
    //         poss &= minDis[i][idx_B] >= dis;
    //     }
    //     if (!poss) continue;

    //     for (auto &nxt_idx_B : allB[a[idx_A + 1]]) {
    //         poss = 1;
    //         for (int i = idx_A + 2; i < n && poss; i++) {
    //             poss &= minDis[i][nxt_idx_B] > abs(idx_B - nxt_idx_B) + dis;
    //         }
    //         if (poss && ckmin(minDis[idx_A + 1][nxt_idx_B], abs(idx_B - nxt_idx_B) + dis)) {
    //             q.insert({minDis[idx_A + 1][nxt_idx_B], {-(idx_A + 1), nxt_idx_B}});
    //             // if ((int)q.size() > 10 * n * m) q.erase(--q.end());
    //             // q.push({-(idx_A + 1), {minDis[idx_A + 1][nxt_idx_B], nxt_idx_B}});
    //             // q.push({minDis[idx_A + 1][nxt_idx_B], {-(idx_A + 1), nxt_idx_B}});
    //         }
    //     }
    // }

    // hash_map<pair<int, int>, ll> mp;
    // auto sol = y_combinator([&](auto self, int currInB, int posInA) -> ll {
    //     if (posInA == n) return 0;
    //     // dbg(currInB, posInA);
    //     auto it = mp.find(make_pair(currInB, posInA));
    //     if (it != mp.end()) return it->second;

    //     int val = a[posInA];
    //     ll res = 4e18;

    //     for (auto &pos : allB[val]) {
    //         res = min(res, abs(pos - currInB) + self(pos, posInA + 1));
    //     }

    //     // int r = int(lower_bound(allB[val].begin(), allB[val].end(), currInB) - allB[val].begin());
    //     // if (r == (int)allB[val].size()) {
    //     //     r--;
    //     //     r = allB[val][r];
    //     //     res = abs(currInB - r) + self(r, posInA + 1);
    //     // } else {
    //     //     int l = r - 1;
    //     //     r = allB[val][r];
    //     //     res = abs(currInB - r) + self(r, posInA + 1);
    //     //     if (l >= 0) l = allB[val][l], res = min(res, abs(currInB - l) + self(l, posInA + 1));
    //     // }
    //     mp[{currInB, posInA}] = res;
    //     return res;
    // });

    // for (int i = 0; i < m; i++) {
    //     if (b[i] == a[0]) {
    //         ans = min(sol(i, 1), ans);
    //     }
    // }
    vector<ll> dp(m);
    for (auto &x : a) {
        for (int i = 1; i < m; i++) {
            ckmin(dp[i], dp[i - 1] + 1);
        }
        for (int i = m - 2; i >= 0; i--) {
            ckmin(dp[i], dp[i + 1] + 1);
        }
        for (int i = 0; i < m; i++) {
            if (b[i] != x) dp[i] = 4e18;
        }
    }

    cout << "Case #" << _TC << ": ";
    cout << *min_element(dp.begin(), dp.end()) << '\n';
    // cout << *min_element(minDis[n - 1].begin(), minDis[n - 1].end()) << '\n';
    // cout << ans << '\n';
    // cout << *min_element(dp_prev.begin(), dp_prev.end()) << '\n';
    // ll res = 4e18;
    // for (auto &[_, cost] : s) {
    //     res = min(res, cost);
    // }
    // cout << res << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    for (int TC = 1; TC <= TT; TC++) {
        solve(TC);
    }

    return 0;
}