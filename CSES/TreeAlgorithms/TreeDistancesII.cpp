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

    int n;
    cin >> n;
    auto adj = reG(n, n - 1);

    ll _sum = 0;
    vector<int> sub(n);
    sub[0] = y_combinator([&](auto self, int v, int p, int dep) -> int {
        _sum += dep;
        sub[v] = 1;
        for (auto &u : adj[v]) {
            if(u != p) sub[v] += self(u, v, dep + 1);
        }
        return sub[v];
    })(0, -1, 0);

    vector<ll> sum(n);
    sum[0] = _sum;

    y_combinator([&](auto self, int v, int p) -> void {
        if(v) {
            sum[v] = sum[p] - 2 * sub[v] + n;
        }
        for (auto &u : adj[v]) {
            if(u != p) self(u, v);
        }
    })(0, -1);

    ov(sum);

    return 0;
}