/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
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


void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i], --a[i];
    for (int i = 0; i < n; i++) cin >> b[i], --b[i];

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }

    vector<bool> vis(n);
    int cnt = 0;
    auto dfs = y_combinator([&](auto self, int v) -> void {
        vis[v] = 1;
        cnt++;
        for (auto &u : adj[v]) {
            if (!vis[u]) self(u);
        }
    });

    vector<int> grp;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cnt = 0;
            dfs(i);
            grp.push_back(cnt);
        }
    }

    set<int> s;
    for (int i = 0; i < n; i++) s.insert(i + 1);

    ll res = 0;
    for (auto &g : grp) {
        for (int i = 0; i < g / 2; i++) {
            res += 2 * abs(*s.begin() - *s.rbegin());
            s.erase(s.begin());
            s.erase(--s.end());
        }
    }
    cout << res << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}
