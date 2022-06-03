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

constexpr int pct(int x) { return __builtin_popcount(x); }                                  // # of bits set
constexpr int log_2(int x) { return x ? (8 * (int)sizeof(x)) - 1 - __builtin_clz(x) : -1; } // Floor of log_2(x); index of highest 1-bit
constexpr int next_pow_2(int x) { return x > 0 ? 1 << log_2(2 * x - 1) : 0; }               // 16->16, 13->16, (x<=0)->0
constexpr int log_2_ceil(int x) { return log_2(x) + int(__builtin_popcount(x) != 1); }      // Ceil of log_2(x);


template <class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template <class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

const int N = 2e5 + 7;
array<int, 2> Q[N];
int state[N];
int par[N];
int upar[N];

int up[N][18];
// Not working, break up components
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(15) << fixed;

    int n, q;
    cin >> n >> q;
    vector<set<int>> adj(n);
    vector<vector<int>> adj_c(n);
    vector<int> to_self;
    for (int i = 0; i < n; i++) {
        cin >> par[i]; par[i]--;
        adj[par[i]].insert(i);;
        if(par[i] == i) to_self.push_back(i);
    }
    sort(to_self.begin(), to_self.end());
    set<int> cycle;

    auto find_cycle = y_combinator([&](auto self, int v) -> bool {
        state[v] = 1;
        for (auto u : adj[v]) {
            if(state[u] == 1) {
                do {
                    adj[par[u]].erase(u);
                    adj_c[u].push_back(par[u]);
                    upar[par[u]] = u;
                    cycle.insert(u);
                    u = par[u];
                } while(!cycle.count(u));
                return true;
            } else if (!state[u]) {
                if(self(u)) return true;
            }
        }
        state[v] = 2;
        return false;
    });

    for (int i = 0; i < n; i++) {
        !state[i] && find_cycle(i);
    }
    dbg(adj);
    dbg(adj_c);

    vector<array<int, 2>> depth(n);
    vector<array<int, 2>> depth_c(n);
    for (int i = 0; i < n; i++) depth_c[i][1] = -1;
    memset(up, -1, n * 18);

    int x = -1;
    auto cal_depth = y_combinator([&](auto self, int v, int dep, bool cy) -> void {
        if(cy) {
            depth_c[v] = {dep, x};
            for (auto &u : adj_c[v]) {
                if (depth_c[u][1] == -1) self(u, dep + 1, cy);
            }
            return;
        }

        depth[v] = {dep, x};
        if(v == x) {
            for (int lvl = 0; lvl < 18; lvl++) {
                up[x][lvl] = x;
            }
        } else {
            up[v][0] = par[v];
            for (int lvl = 1; lvl < 18; lvl++) {
                up[v][lvl] = up[up[v][lvl - 1]][lvl - 1];
            }
        }

        for (auto &u : adj[v]) {
            self(u, dep + 1, cy);
        }
    });

    for (auto &r : cycle) {
        x = r;
        cal_depth(r, 0, 0);
        if(depth_c[r][1] == -1) {
            cal_depth(r, 0, 1);
        }
    }

    dbg(cycle);
    dbg(to_self);
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b; a--, b--;

        if(a == b) {
            cout << 0 << '\n';
        } else if(cycle.count(a) && cycle.count(b)) {
            if(depth_c[b][1] == depth_c[a][1]) {
                int d = depth_c[b][0] - depth_c[a][0];
                dbg(d);
                if(d < 0) {
                    d += depth_c[upar[depth_c[b][1]]][0] + 1;
                }
                cout << d << '\n';
            } else 
                cout << -1 << '\n';
        } else if (cycle.count(b)) {
            if(depth_c[b][1] == depth_c[depth[a][1]][1]) {
                int d = depth_c[b][0] - depth_c[depth[a][1]][0];
                if(d < 0) {
                    d += depth_c[upar[depth_c[b][1]]][0] + 1;
                }
                cout << d + depth[a][0] << '\n';
            } else 
                cout << -1 << '\n';
        } else if(!(cycle.count(a) || cycle.count(b))) {
            if(depth[a][1] == depth[b][1] && depth[a][0] >= depth[b][0]) {
                int k = depth[a][0] - depth[b][0];
                for (int lvl = 17; lvl >= 0; lvl--) {
                    if((k >> lvl) & 1) {
                        a = up[a][lvl];
                    }
                }
                if(a == b) {
                    cout << k << '\n';
                } else {
                    cout << -1 << '\n';
                }
            } else {
                cout << -1 << '\n';
            }
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}