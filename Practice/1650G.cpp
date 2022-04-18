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

template <class T> void remDupf(vector<T> &v) { sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), end(v)); }


void solve() {
    int n, m, s, e; cin >> n >> m >> s >> e; s--, e--;
    auto adj = reG(n, m);

    vector<bool> vis(n); vis[s] = 1;
    queue<int> q; q.push(s);
    set<int> q1;
    vector<int> vis_curr, dis(n); int _dis = 0;
    vector<vector<int>> p(n);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto u : adj[v]) {
            if(!vis[u]) {
                vis_curr.push_back(u);
                p[u].push_back(v);
                q1.insert(u);
                dis[u] = _dis;
            }
        }

        if(q.empty()) {
            for (auto &u : vis_curr) {
                vis[u] = 1;
            }
            if(q1.count(e)) break;
            for (auto &u : q1) {
                q.push(u);
            }
            q1.clear(), vis_curr.clear(); _dis++;
        }
    }

    vector<int> rightPath;

    q = queue<int>(); q.push(e);
    fill(vis.begin(), vis.end(), 0); vis[e] = 1;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        rightPath.push_back(v);

        for (auto &u : p[v]) {
            if(!vis[u]) {
                vis[u] = 1;
                q.push(u);
            }
        }
    }

    remDupf(rightPath);

    



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