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

const int MOD = 1e9 + 007; // 998244353;

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
        // adj[u].push_back(v);
        // if(bi) 
        adj[v].push_back(u);
    }
    return adj;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(15) << fixed;

    int n, m; cin >> n >> m;
    auto adj = reG(n, m, 0);
    vector<int> res(n); res[0] = 1;
    vector<bool> vis(n); vis[0] = 1;
    cout << y_combinator([&](auto self, int v) -> int {
        if(vis[v]) return res[v];
        else vis[v] = 1;
        ll ans = 0;
        for (auto &u : adj[v]) {
            if(vis[u]) ans += res[u];
            else ans += self(u);
        }
        res[v] = ans % MOD;
        return res[v];
    })(n - 1) << '\n';

    return 0;
}