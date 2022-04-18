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

template <class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template <class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


void solve(int _TC) {
    int n; cin >> n;
    vector<ll> f(n);
    for (int i = 0; i < n; i++) cin >> f[i];
    vector<int> adj(n);
    vector<int> in_degree(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x; x--;
        adj[i] = x;
        if(x >= 0) in_degree[x]++;
        if(i == x) in_degree[x]--;
    }
    vector<int> initiator;
    for (int i = 0; i < n; i++) if(in_degree[i] == 0) initiator.push_back(i);

    ll best = 0, curr = 0;
    vector<bool> vis(n);
    auto dfs = y_combinator([&](auto self, int v, ll carry) -> void {
        vis[v] = 1;
        int u = adj[v];
        if(u == -1 || vis[u]) {
            curr += carry;
            return;
        }
        self(u, max(carry, f[u]));
    });

    do {
        fill(vis.begin(), vis.end(), 0);
        curr = 0;
        for (auto &u : initiator) {
            dfs(u, f[u]);
        }
        best = max(best, curr);
    } while(next_permutation(initiator.begin(), initiator.end()));

    cout << "Case #" << _TC << ": ";
    cout << best << '\n';
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    for (int TC = 1; TC <= TT; TC++) {
        solve(TC);
    }

    return 0;
}