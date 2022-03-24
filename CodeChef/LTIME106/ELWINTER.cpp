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



void solve() {
    int n, m, Q; cin >> n >> m >> Q;
    vector<vector<int>> adj = reG(n, m);
    vector<bool> frozen(n);
    queue<int> q;
    while(Q--) {
        int t; cin >> t;
        if(t == 1) {
            int u; cin >> u; u--;
            if(!frozen[u]) {
                frozen[u] = 1;
                q.push(u);
            }
        } else if(t == 2) {
            int time; cin >> time;
            queue<int> q2;
            while(!q.empty() && time) {
                int v = q.front(); q.pop();
                for (auto &u : adj[v]) {
                    if(!frozen[u]) {
                        frozen[u] = 1; q2.push(u);
                    }
                }
                if(q.empty()) {
                    swap(q, q2); time--;
                }
            }
        } else {
            int v; cin >> v; v--;
            cout << (frozen[v] ? "YES" : "NO") << '\n';
        }
        dbg(frozen);
    }
}

int main() {
    vamos;

    int TT = 1;
    // cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}