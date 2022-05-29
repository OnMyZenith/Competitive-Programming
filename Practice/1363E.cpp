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

int main() {
    vamos;

    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    auto adj = reG(n, n - 1);

    ll cost = 0;
    auto res = y_combinator([&](auto dfs, int v, int p) -> array<int, 2> {
        ckmin(a[v], a[p]);
        array need{0, 0};
        if(b[v] != c[v]) {
            need[0] = !b[v];
            need[1] = b[v];
        }

        for (auto &u : adj[v]) {
            if(u != p) {
                auto val = dfs(u, v);
                for (int i = 0; i < 2; i++) need[i] += val[i];
            }
        }

        int can = min(need[0], need[1]);
        cost += 2LL * can * a[v];
        if(can) {
            need[0] -= can;
            need[1] -= can;
        }

        return need;
    })(0, 0);

    if(res[0] || res[1]) {
        cout << "-1\n";
        return 0;
    }
    cout << cost << '\n';

    return 0;
}