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

vector<vector<array<int, 2>>> reGweighted(int n, int m, bool bi = 0) {
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
template <typename T_vector> void ov(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(15) << fixed;

    int n, m; cin >> n >> m;
    vector<array<ll, 3>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        u--, v--;
        edges[i] = {u, v, x};
    }

    vector<ll> dis(n, 4e18); dis[0] = 0;
    int c = -1;
    vector<int> p(n, -1);
    for (int i = 0; i < n; i++) {
        c = -1;
        for (auto &[u, v, w] : edges) {
            if (ckmin(dis[v], dis[u] + w)) {
                c = (int)v;
                p[v] = (int)u;
            }
        }
    }
    if(c != -1) {
        for (int i = 0; i < n; i++) c = p[c];
        vector<int> cycle = {c};

        while (p[c] != -1) {
            c = p[c];
            cycle.push_back(c);
            if(c == cycle.front()) break;
        }
        reverse(cycle.begin(), cycle.end());
        cout << "YES\n";
        ov(cycle, 1);
    } else cout << "NO\n";

    return 0;
}