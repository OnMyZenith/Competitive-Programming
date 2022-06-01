/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

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

vector<vector<int>> reG(int n, int m, bool bi = 1) {
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        if(bi) adj[v].push_back(u);
    }
    return adj;
}

template <class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template <class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

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
    size_t operator()(array<uint64_t, 3> x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x[0] + FIXED_RANDOM) ^ splitmix64(x[1] + FIXED_RANDOM) ^ splitmix64(x[2] + FIXED_RANDOM);
    }
};

template <class T, class U, typename Hash = splitmix64_hash> using hash_map = gp_hash_table<T, U, Hash>;
template <class T, typename Hash = splitmix64_hash> using hash_set = hash_map<T, null_type, Hash>;


void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    auto adj = reG(n, n - 1);

    map<array<int, 3>, int> mp;
    auto fun = y_combinator([&](auto self, int v, int p, bool changed, int color) -> int {
        if((int)adj[v].size() == 1 && adj[v][0] == p) {
            if(changed) return color != b[v];
            else return a[v] != b[v];
        }
        auto it = mp.find(array<int, 3>{v, (int)changed, (int)changed * color});
        if(it != mp.end()) return it->second;

        int res = 1e9;
        if(!changed) {
            if(a[v] == b[v])  {
                int s1 = 1, s2 = 0;
                for (auto &u : adj[v]) {
                    if(u != p) {
                        s1 += self(u, v, 1, b[v]);
                        s2 += self(u, v, 0, -1);
                    }
                }
                ckmin(res, min(s1, s2));
            } else {
                int s = 1;
                for (auto &u : adj[v]) {
                    if(u != p) s += self(u, v, 1, b[v]);
                }
                ckmin(res, s);
            }
        } else {
            if (color == b[v]) {
                int s = 0;
                for (auto &u : adj[v]) {
                    if(u != p) s += self(u, v, 1, b[v]);
                }
                ckmin(res, s);
            } else {
                int s = 1;
                for (auto &u : adj[v]) {
                    if(u != p) s += self(u, v, 1, b[v]);
                }
                ckmin(res, s);
            }
        }
        mp[array<int, 3>{v, (int)changed, (int)changed * color}] = res;
        return res;
    });
    int ans = fun(0, -1, 0, 1);
    cout << ans << '\n';
}

int main() {
    vamos;
    auto begin = chrono::high_resolution_clock::now();
    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }
    auto end = chrono::high_resolution_clock::now();
    cerr << setprecision(2) << fixed;
    cerr << "My Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count() * 1000 << " ms" << endl;

    return 0;
}