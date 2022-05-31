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

int main() {
    vamos;

    int n, m, Q; cin >> n >> m >> Q;
    vector<vector<ll>> dis(n, vector<ll>(n, 4e18));
    for (int i = 0; i < m; i++) {
        int u, v, e; cin >> u >> v >> e;
        u--, v--;
        ckmin(dis[u][v], (ll)e);
        dis[v][u] = dis[u][v];
    }
    for (int i = 0; i < n; i++) dis[i][i] = 0;

    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            for (int i = j + 1; i < n; i++) {
                ckmin(dis[i][j], dis[i][k] + dis[j][k]);
                dis[j][i] = dis[i][j];
            }
        }
    }

    while(Q--) {
        int u, v; cin >> u >> v; u--, v--;
        cout << (dis[u][v] != (ll)4e18 ? dis[u][v] : -1) << '\n';
    }

    return 0;
}