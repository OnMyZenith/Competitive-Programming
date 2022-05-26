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

template <class T> using pqdec = std::priority_queue<T>;
template <class T> using pqinc = std::priority_queue<T, vector<T>, greater<T>>;

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }
template <typename T_vector> void ov(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}


int main() {
    vamos;

    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, e; cin >> u >> v >> e;
        u--, v--;
        adj[u].push_back({e, v});
    }

    vector<ll> to(n, 4e18);
    to[0] = 0;

    pqinc<pair<ll, int>> q; q.push({0, 0});
    while(!q.empty()) {
        auto [d_v, v] = q.top(); q.pop();

        if(d_v != to[v]) continue;

        for (auto &[len, u] : adj[v]) {
            if (ckmin(to[u], d_v + len)) {
                q.push({to[u], u});
            }
        }
    }

    ov(to);

    return 0;
}