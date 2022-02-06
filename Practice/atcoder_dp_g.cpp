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


vector<int> in_degree;
vector<vector<int>> reG(int n, int m, bool bi = 1) {
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        in_degree[v]++;
        if(bi) adj[v].push_back(u);
    }
    return adj;
}

int main() {
    vamos;

    int n, m; cin >> n >> m;
    in_degree.assign(n, 0);
    auto g = reG(n, m, 0);
    for (int i = 0; i < n; i++) g[n].push_back(i), in_degree[i]++;

    vector<int> dep(n+1, 0); dep[n] = -1;
    y_combinator([&](auto dfs, int v)->void{
        for (auto &u : g[v]) {
            ckmax(dep[u], dep[v] + 1);
            in_degree[u]--;
            if(in_degree[u]==0) dfs(u);
        }
    })(n);
    cout << *max_element(dep.begin(), dep.end()) << '\n';
    return 0;
}