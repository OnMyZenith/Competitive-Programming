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

vector<vector<int>> adj;
const int N = 2e5 + 7;
ll res[N], cnt[N], ans;
int n;

array<ll, 2> dfs(int v, int p) {
    ll ans_ = 0, cnt_ = 1;
    for (auto &u : adj[v]) {
        if (u != p) {
            array<ll, 2> val = dfs(u, v);
            ans_ += val[0];
            cnt_ += val[1];
        }
    }
    cnt[v] = cnt_;
    res[v] = ans_ + cnt_;
    return array<ll, 2>{ans_ + cnt_, cnt_};
}

void reroot(int v, int p) {
    ans = max(res[v], ans);
    for (auto &u : adj[v]) {
        if (u != p) {
            cnt[v] -= cnt[u];
            res[v] -= cnt[u] + res[u];
            cnt[u] = (int)adj.size();
            res[u] += cnt[v] + res[v];
            reroot(u, v);
            swap(u, v);
            cnt[v] -= cnt[u];
            res[v] -= cnt[u] + res[u];
            cnt[u] = (int)adj.size();
            res[u] += cnt[v] + res[v];
            swap(u, v);
        }
    }
}

void anotherMethod(int v, int p, ll score) {
    ans = max(score, ans);
    for (auto &u : adj[v]) {
        if (u != p) anotherMethod(u, v, score + n - 2 * cnt[u]);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    cin >> n;
    adj = reG(n, n - 1);
    dfs(0, -1);
    // reroot(0, -1);
    anotherMethod(0, -1, res[0]);
    cout << ans << '\n';

    return 0;
}