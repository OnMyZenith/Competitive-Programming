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

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

template <typename T_vector> void ov(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(15) << fixed;

    int n, m; cin >> n >> m;
    auto adj = reG(n, m, 0);

    deque<pair<int, int>> q; q.push_front({0, 0});
    vector<int> d(n, -(int)1e9); d[0] = 0;
    vector<int> p(n, -1);
    while (!q.empty()) {
        auto [dis, v] = q.front(); q.pop_front();
        if(dis < d[v]) continue;
        for (auto &u : adj[v]) {
            if (ckmax(d[u], d[v] + 1)) {
                q.push_front({d[u], u});
                p[u] = v;
            }
        }
    }
    if(d[n - 1] == -(int)1e9) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<int> path = {n - 1};
    int x = p[n - 1];
    while(x != -1) path.push_back(x), x = p[x];
    reverse(path.begin(), path.end());
    cout << (int)path.size() << '\n';
    assert((int)path.size() == d[n - 1] + 1);
    ov(path, 1);
    return 0;
}