/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
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

template <class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template <class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n; cin >> n;
    auto adj = reG(n, n - 1);
    int LGMX = int(ceil(log2(n)) + 2);
    vector<vector<int>> up(n, vector<int>(LGMX, -1));
    vector<int> dep(n);
    y_combinator([&](auto self, int v, int p) -> void {
        if (p < 0) {
            up[v][0] = v;
            dep[v] = 0;
        } else up[v][0] = p, dep[v] = dep[p] + 1;

        for (int lvl = 1; lvl < LGMX; lvl++) {
            up[v][lvl] = up[up[v][lvl - 1]][lvl - 1];
        }

        for (auto &u : adj[v]) {
            if (u != p) self(u, v);
        }
    })(0, -1);

    auto getAncestor = [&](int v, int steps) -> int {
        for (int j = 0; j < LGMX; j++) {
            if (steps >> j & 1) {
                v = up[v][j];
            }
        }
        return v;
    };

    auto getLCA = [&](int u, int v) -> int {
        if (dep[u] > dep[v]) swap(u, v);
        v = getAncestor(v, dep[v] - dep[u]);

        int lo = -1, hi = n;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if(getAncestor(u, mid) == getAncestor(v, mid)) hi = mid - 1;
            else lo = mid;
        }
        if (lo < 0) return v;
        return up[getAncestor(v, lo)][0];
    };

    int nqs; cin >> nqs;
    while (nqs--) {
        int k; cin >> k;
        vector<int> p(k);
        for (auto &u : p) {
            cin >> u; --u;
        }
        sort(p.begin(), p.end(), [&](int i, int j) {return dep[i] > dep[j];});

        vector<bool> seen(k); seen[0] = 1;

        int p1 = 0, p2 = -1;
        for (int i = 1; i < k; i++) {
            if (getLCA(p[i], p[0]) == p[i]) seen[i] = 1, p1 = i;
        }
        int d2 = -1;
        for (int i = 0; i < k ; i++) {
            if (!seen[i]) {
                if (d2 == -1) d2 = p[i], seen[i] = 1, p2 = i;
                else {
                    if (getLCA(d2, p[i]) == p[i]) seen[i] = 1, p2 = i;
                }
            }
        }
        bool poss = count(seen.begin(), seen.end(), 1) == k;
        if (d2 != -1) {
            int x = getLCA(p[0], d2);
            poss &= dep[x] <= dep[p[k - 1]];
        }

        cout << (poss ? "YES" : "NO") << '\n';
    }

    return 0;
}
