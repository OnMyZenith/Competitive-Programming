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

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }
template <class T> using pqdec = std::priority_queue<T>;
template <class T> using pqinc = std::priority_queue<T, vector<T>, greater<T>>;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(15) << fixed;

    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c; a--, b--;
        adj[a].push_back({b, c});
    }

    vector<array<ll, 2>> cost(n, {INT64_MAX, INT64_MAX}); cost[0] = {0, 0};

    struct Pos {
        int v; bool used; ll cost;
    };

    auto cmp = [&](Pos v, Pos u) -> bool {
        return v.cost > u.cost;
    };

    std::priority_queue<Pos, vector<Pos>, decltype(cmp)> q(cmp); q.push({0, false, 0});

    while(!q.empty()) {
        Pos curr = q.top(); q.pop();
        if(cost[curr.v][curr.used] != curr.cost) continue;

        for (auto &[u, c] : adj[curr.v]) {
            if (ckmin(cost[u][curr.used], cost[curr.v][curr.used] + c)) {
                q.push({u, curr.used, cost[u][curr.used]});
            }
            if(!curr.used) {
                if (ckmin(cost[u][1], cost[curr.v][0] + c / 2)) {
                    q.push({u, 1, cost[u][1]});
                }
            }
        }
    }
    dbg(cost);
    cout << cost[n - 1][1] << '\n';

    return 0;
}