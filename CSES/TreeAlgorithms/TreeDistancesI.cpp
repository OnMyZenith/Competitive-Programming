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
        if (bi) adj[v].push_back(u);
    }
    return adj;
}

template <class T>
bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T>
bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

template <class Fun>
class y_combinator_result {
    Fun fun_;

public:
    template <class T>
    explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args>
    decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun>
decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(15) << fixed;

    int n;
    cin >> n;
    auto adj = reG(n, n - 1);

    array vert{0, -1, -1};
    vector<vector<int>> depth(n, vector<int>(2));
    int mx = 0, f = 0;
    for (auto &w : vert) {
        y_combinator([&](auto dfs, int v, int p, int dep) -> void {
            if (ckmax(mx, dep) && f <= 1) vert[f + 1] = v;
            if (f == 1) depth[v][0] = dep;
            else if (f == 2)
                depth[v][1] = dep;

            for (auto &u : adj[v]) {
                if (u != p) {
                    dfs(u, v, dep + 1);
                }
            }
        })(w, -1, 0);
        f++; mx = 0;
    }

    for (int i = 0; i < n; i++)
        cout << max(depth[i][0], depth[i][1]) << " \n"[i == n - 1];

    return 0;
}