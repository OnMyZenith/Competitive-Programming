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

// Because multiset.erase(ele) will erase all occurances of ele!!
template <class T, class U> bool erase(T &t, const U &u) {
    auto it = t.find(u);
    if (it == end(t)) return false;
    t.erase(it); return true;
}

void solve() {
    int n, Q; cin >> n >> Q;
    vector<vector<int>> adj(n);
    map<int, set<int>> g;
    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].insert(v);
        g[v].insert(u);
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    auto _g = g; auto _deg = deg;
    ll ans = 0;
    queue<int> q;
    for (int i = 0; i < n; i++) if(deg[i] == 1) {
        q.push(i);
    }
    while (!q.empty()) {
        int v = q.front(); q.pop();
        auto u = g[v].begin();
        if(g[v].end() == u) continue;

        ans += deg[*u]--;
        if(deg[*u] == 1) q.push(*u);
        g[*u].erase(v);
        g[v].erase(u);
    }
    cout << ans << '\n';
    
    while(Q--) {
        int a, b, c, d; cin >> a >> b >> c >> d; a--, b--, c--, d--;
        g = _g, deg = _deg;
        g[a].erase(b), g[b].erase(a), deg[a]--, deg[b]--;
        g[c].insert(d), g[d].insert(c), deg[c]++, deg[d]++;
        ll ans = 0;
        queue<int> q;
        for (int i = 0; i < n; i++) if(deg[i] == 1) {
            q.push(i);
        }
        while (!q.empty()) {
            int v = q.front(); q.pop();
            auto u = g[v].begin();
            if(g[v].end() == u) continue;

            ans += deg[*u]--;
            if(deg[*u] == 1) q.push(*u);
            g[*u].erase(v);
            g[v].erase(u);
        }
        cout << ans << '\n';
    }


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