/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


void solve(int _TC) {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> adj(n), grp(n);
    vector<int> in_deg(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        grp[v].push_back(u);
        in_deg[v]++;
    }
    vector<int> inn(n, 1);
    for (int cs = 0; cs < n; cs++) {
        if (!inn[cs]) continue;
        bool poss = 1;
        queue<int> q;
        q.push(cs);
        set<int> enqueued; enqueued.insert(cs);
        while (!q.empty() && poss) {
            int v = q.front(); q.pop();
            for (auto &u : grp[v]) {
                if (!enqueued.count(u)) {
                    enqueued.insert(u);
                    if ((int)enqueued.size() > k) {
                        poss = 0;
                        break;
                    }
                    q.push(u);
                }
            }
        }

        if (poss) {
            for (auto &v: enqueued)
                inn[v] = 0;
        }
    }

    cout << "Case #" << _TC << ": ";
    cout << count(inn.begin(), inn.end(), 1) << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    for (int TC = 1; TC <= TT; TC++) {
        solve(TC);
    }

    return 0;
}