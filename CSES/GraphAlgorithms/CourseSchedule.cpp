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
    vector<int> topsort;

    vector<int> p(n, -1), state(n);
    auto find_cycle = y_combinator([&](auto self, int v) -> bool {
        state[v] = 1;
        for (auto &u : adj[v]) {
            if(state[u] == 1) {
                // p[u] = v;
                // vector<int> cycle = {u, v};
                // while (v != u) v = p[v], cycle.push_back(v);
                // cout << (int)cycle.size() << '\n';
                // reverse(cycle.begin(), cycle.end());
                // ov(cycle, 1);
                return 1;
            } else if (!state[u]) {
                p[u] = v;
                if(self(u)) {
                    return 1;
                }
            }
        }

        state[v] = 2;
        topsort.push_back(v);
        return 0;
    });
    for (int i = 0; i < n; i++) {
        if(!state[i] && find_cycle(i)) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    reverse(topsort.begin(), topsort.end());
    ov(topsort, 1);

    return 0;
}