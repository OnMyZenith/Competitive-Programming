/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
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

void solve() {
    int n; cin >> n;
    auto adj = reG(n, n - 1);

    vector<int> subsz(n);
    subsz[0] = y_combinator([&](auto dfs, int v, int p) -> int {
        int c = 0;
        for (auto &u : adj[v]) {
            if(u != p) {
                c += dfs(u, v);
            }
        }
        subsz[v] = c + 1;
        return c + 1;
    })(0, -1);

    int ans = 0;
    vector<array<int, 2>> dp(n, array<int, 2>{0, 0});
    vector<array<bool, 2>> done(n, array<bool, 2>{0, 0});
    // dp[v][1] <- score if killed first child
    // dp[v][0] <- score if killed second child
    for (int _a : {0, 1}) {
        ans = max(ans, y_combinator([&](auto dfs, int v, int p, bool kill_first) -> int {
            if(done[v][kill_first]) return dp[v][kill_first];

            int c = 0;
            for (auto &u : adj[v]) {
                if(u != p) {
                    c++;
                }
            }

            if(c == 1 && !kill_first) {
                done[v][kill_first] = 1;
                dp[v][kill_first] = 0;
                return 0;
            }
            if(c == 1) {
                for (auto &u : adj[v]) {
                    if (u != p) {
                        done[v][kill_first] = 1;
                        dp[v][kill_first] = subsz[u] - 1;
                        return subsz[u] - 1;
                    }
                }
            }
            
            // c == 2, kill_first

            if(kill_first) {
                bool f = 1;
                for (auto &u : adj[v]) {
                    if(u != p) {
                        if (f) {
                            dp[v][1] = subsz[u] - 1;
                            f = 0;
                        } else {
                            int x = dfs(u, v, 0);
                            int y = dfs(u, v, 1);
                            x = max(x, y);
                            dp[v][1] += x;
                            // dp[v][1] += max(dfs(u, v, 0) + dfs(u, v, 1));
                        }
                    }
                }
                done[v][kill_first] = 1;
                return dp[v][kill_first];
            }
            
            bool f = 1;
            for (auto &u : adj[v]) {
                if(u != p) {
                    if (f) {
                        int x = dfs(u, v, 0);
                        int y = dfs(u, v, 1);
                        x = max(x, y);
                        dp[v][0] = x;
                        // dp[v][0] += max((int)dfs(u, v, 0) + (int)dfs(u, v, 1));
                        f = 0;
                    } else {
                        dp[v][0] += subsz[u] - 1;
                    }
                }
            }
            done[v][kill_first] = 1;
            return dp[v][kill_first];
        })(0, -1, _a));
    }
    dbg(dp);
    cout << ans << '\n';
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