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

template <class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template <class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


int LOG = 18;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(15) << fixed;

    int n, q; cin >> n >> q;
    vector<vector<int>> up(n, vector<int>(LOG));
    vector<vector<int>> adj(n);
    up[0][0] = -1;
    for (int i = 1; i < n; i++) {
        int p; cin >> p, p--;
        up[i][0] = p;
        adj[p].push_back(i);
    }

    vector<int> depth(n);
    y_combinator([&](auto self, int v, int dep) -> void {
        depth[v] = dep;
        for (auto &u : adj[v]) {
            self(u, dep + 1);
        }
    })(0, 0);

    int mx_dep = *max_element(depth.begin(), depth.end());
    LOG = 0;
    while((1 << LOG) <= mx_dep) LOG++;

    for (int lvl = 0; lvl < LOG - 1; lvl++) {
        for (int v = 0; v < n; v++) {
            up[v][lvl + 1] = up[max(up[v][lvl], 0)][lvl];
        }
    }

    auto find_kth_par = [&](int v, int k) -> int {
        for (int lvl = LOG - 1; lvl >= 0; lvl--) {
            if((k >> lvl) & 1) {
                v = up[max(v, 0)][lvl];
            }
        }
        return v;
    };
    while (q--) {
        int v, u; cin >> v >> u; v--, u--;

        if(depth[v] < depth[u]) {
            swap(v, u);
        }
        
        v = find_kth_par(v, depth[v] - depth[u]);
        if(v == u) {
            cout << v + 1 << " \n"[!q];
            continue;
        }

        for (int lvl = LOG - 1; lvl >= 0; lvl--) {
            if(up[v][lvl] != up[u][lvl]) {
                v = up[v][lvl];
                u = up[u][lvl];
            }
        }
        cout << up[v][0] + 1 << " \n"[!q];
    }

    return 0;
}