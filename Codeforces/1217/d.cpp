/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<pair<pair<int, int>, int>> edges(m);
    vector<int> res(m);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        edges[i] = {{u, v}, i};
        adj[u].push_back(v);
    }
    sort(edges.begin(), edges.end());

    int color = 1;
    vector<pair<int, int>> moar;
    vector<int> state(n, 0);
    auto dfs = y_combinator([&](auto self, int v, int c) -> void {
        state[v] = 1;
        for (auto &u : adj[v]) {
            if (state[u] == 1) {
                moar.push_back({v, u});
            } else {
                res[edges[int(lower_bound(edges.begin(), edges.end(), make_pair(make_pair(v, u), -1)) - edges.begin())].second] = c;
                if (state[u] == 0) self(u, c);
            }
        }
        state[v] = 2;
    });

    for (int i = 0; i < n; i++) {
        if (state[i] == 0) {
            dfs(i, color);
        }
    }

    while (!moar.empty()) {
        color++;
        fill(adj.begin(), adj.end(), vector<int>{});
        for (auto &[u, v] : moar) {
            adj[u].push_back(v);
        }
        moar.clear();
        fill(state.begin(), state.end(), 0);
        for (int i = 0; i < n; i++) {
            if (state[i] == 0) {
                dfs(i, color);
            }
        }
    }

    cout << color << '\n';
    for (int i = 0; i < m; i++) cout << res[i] << " \n"[i == m - 1];

    return 0;
}