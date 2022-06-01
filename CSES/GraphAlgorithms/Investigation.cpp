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

vector<vector<array<int, 2>>> reGweighted(int n, int m, bool bi = 1) {
    vector<vector<array<int, 2>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        u--, v--;
        adj[u].push_back({v, x});
        if(bi) adj[v].push_back({u, x});
    }
    return adj;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(15) << fixed;

    int n, m; cin >> n >> m;
    auto adj = reGweighted(n, m, 0);

    struct City {
        ll dis;
        int tot_routes;
        int min_f;
        int max_f;
    };
    vector<City> c(n, {ll(4e18), 0, 0, 0}); c[0] = {0, 1, 0, 0};

    std::priority_queue<pair<ll , int>, vector<pair<ll , int>>, greater<pair<ll, int>>> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto [this_dis, v] = q.top(); q.pop();

        if(c[v].dis < this_dis) continue;

        for (auto &[u, w] : adj[v]) {
            if(w + c[v].dis < c[u].dis) {
                c[u].dis = w + c[v].dis;
                c[u].tot_routes = c[v].tot_routes;
                c[u].max_f = c[v].max_f + 1;
                c[u].min_f = c[v].min_f + 1;
                q.push({c[u].dis, u});
            } else if (w + c[v].dis == c[u].dis) {
                (c[u].tot_routes += c[v].tot_routes) >= MOD ? c[u].tot_routes -= MOD : c[u].tot_routes;
                c[u].min_f = min(c[u].min_f, c[v].min_f + 1);
                c[u].max_f = max(c[u].max_f, c[v].max_f + 1);
            }
        }
    }

    cout << c[n - 1].dis << " " << c[n - 1].tot_routes << " " << c[n - 1].min_f << " " << c[n - 1].max_f << '\n';

    return 0;
}