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
        if (bi) adj[v].push_back(u);
    }
    return adj;
}

template <class T>
bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T>
bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

template <class Fun>
class y_combinator_result {
    Fun fun_;

public:
    template <class T>
    explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args>
    decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun>
decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
const int LOG = 18;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(15) << fixed;

    int n, q; cin >> n >> q;
    vector<vector<int>> up(n, vector<int>(LOG));
    up[0][0] = -1;
    for (int i = 1; i < n; i++) cin >> up[i][0], up[i][0]--;

    for (int lvl = 0; lvl < LOG - 1; lvl++) {
        for (int v = 0; v < n; v++) {
            up[v][lvl + 1] = up[max(up[v][lvl], 0)][lvl];
        }
    }
    
    while (q--) {
        int v, k; cin >> v >> k; v--;
        for (int lvl = 17; lvl >= 0; lvl--) {
            if(k >> lvl) {
                k ^= 1 << lvl;
                v = up[max(v, 0)][lvl];
            }
        }
        cout << (++v ? v : -1) << " \n"[!q];
    }

    return 0;
}