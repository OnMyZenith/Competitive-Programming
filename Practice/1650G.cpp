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

template <class T> using pqdec = std::priority_queue<T>;
template <class T> using pqinc = std::priority_queue<T, vector<T>, greater<T>>;
const int INF = 1e9;
const int MOD = 1e9 + 7;

void solve() {
    int n, m, s, e; cin >> n >> m >> s >> e; s--, e--;
    auto adj = reG(n, m);

    // best2[v].begin()->first == shortest path to v
    // best2[v].begin()->second == number of ways to get to v with this path

    // best2[v].rbegin()->first == 2nd shortest path to v
    // best2[v].rbegin()->second == number of ways to get to v with this path
    vector<set<pair<int, ll>>> best2(n);

    pqinc<pair<int, int>> q; q.push({0, s});
    best2[s].insert({0, 1});

    while (!q.empty()) {
        auto [d_v, v] = q.top(); q.pop();
        auto it = best2[v].lower_bound({d_v, 0});
        if (it == best2[v].end()) continue;
        else assert(it->first == d_v);
        ll ways_v = it->second;

        for (auto &u : adj[v]) {
            if (best2[u].empty()) {
                best2[u].insert({d_v + 1, ways_v});
            } else {
                it = best2[u].lower_bound({d_v + 1, 0});
                if (it == best2[u].end()) {
                    if ((int)best2[u].size() == 1) {
                        if (best2[u].begin()->first < d_v) continue;
                        else best2[u].insert({d_v + 1, ways_v});
                    } else {
                        continue;
                        // dont pursue edge;
                    }
                } else {
                    if (++it == best2[u].end()) {
                        --it;
                        if (it->first == d_v + 1) {
                            ll tmp = it->second;
                            best2[u].erase(it);
                            best2[u].insert({d_v + 1, (tmp + ways_v) % MOD});
                            continue;
                        } else {
                            best2[u].erase(it);
                            best2[u].insert({d_v + 1, ways_v});
                        }
                    } else {
                        --it;
                        if (it->first == d_v + 1) {
                            ll tmp = it->second;
                            best2[u].erase(it);
                            best2[u].insert({d_v + 1, (tmp + ways_v) % MOD});
                            continue;
                        } else {
                            best2[u].erase(--best2[u].end());
                            best2[u].insert({d_v + 1, ways_v});
                        }
                    }
                }
            }
            q.push({d_v + 1, u});
        }
    }
    cout << (best2[e].begin()->second + ((int)best2[e].size() == 2 && (best2[e].rbegin()->first == best2[e].begin()->first + 1) ? best2[e].rbegin()->second : 0)) % MOD << '\n';
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}