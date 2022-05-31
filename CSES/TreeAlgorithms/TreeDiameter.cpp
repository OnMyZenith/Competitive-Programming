/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
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

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

template <class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template <class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(15) << fixed;

    int n; cin >> n;
    auto adj = reG(n, n - 1);
    int mx = 0;
    y_combinator([&](auto dfs, int v, int p, int dep) -> int {
        array a{0, 0};
        for (auto &u : adj[v]) {
            if(u != p) {
                int one_dep = dfs(u, v, dep + 1);
                if(a[0]) {
                    if(a[0] >= one_dep) ckmax(a[1], one_dep);
                    else a[1] = a[0], a[0] = one_dep;
                } else {
                    a[0] = one_dep;
                }
            }
        }
        ckmax(mx, a[0] + a[1] - 2 * dep);
        return max(a[0], dep);
    })(0, -1, 0);

    cout << mx << '\n';

    return 0;
}