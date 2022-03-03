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

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 0});
    }
    for (int i = 0; i < n; i++) {
        bool f = 1, r = 1;
        for (auto &[ed, w] : adj[i]) {
            if(i - 1 == ed) r = 0;
            if(i + 1 == ed) f = 0;
        }
        if(f && i != n - 1) adj[i].push_back({i + 1, 1});
        if(r && i) adj[i].push_back({i - 1, 1});
    }
    vector<int> d(n, 1e9);
    d[0] = 0;
    deque<int> q;
    q.push_front(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto edge : adj[v]) {
            int u = edge.first;
            int w = edge.second;
            if (d[v] + w < d[u]) {
                d[u] = d[v] + w;
                if (w == 1)
                    q.push_back(u);
                else
                    q.push_front(u);
            }
        }
    }
    cout << d[n - 1] << '\n';
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