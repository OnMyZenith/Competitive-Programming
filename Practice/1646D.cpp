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

int main() {
    vamos;

    int n; cin >> n;
    vector<vector<int>> adj = reG(n, n - 1);
    if(n == 2) {
        cout << "2 2\n1 1\n"; return 0;
    }

    // dp[v][0] -> {most_poss_good_in_this_subtree_if_this_is_bad, min_weight_sum_req_to_achieve_this_config}
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(2));
    y_combinator([&](auto dfs, int v, int p) -> void {
        dp[v][1] = {1, (int)adj[v].size()};
        dp[v][0] = {0, 1};
        for (auto &u : adj[v]) {
            if(u != p) {
                dfs(u, v);

                // making this vertex good
                dp[v][1].first += dp[u][0].first;
                dp[v][1].second += dp[u][0].second;

                // making this vertex bad
                if(dp[u][0].first < dp[u][1].first) {
                    dp[v][0].first += dp[u][1].first;
                    dp[v][0].second += dp[u][1].second;
                } else if(dp[u][0].first > dp[u][1].first) {
                    dp[v][0].first += dp[u][0].first;
                    dp[v][0].second += dp[u][0].second;
                } else {
                    dp[v][0].first += dp[u][0].first;
                    if(dp[u][0].second <= dp[u][1].second) {
                        dp[v][0].second += dp[u][0].second;
                    } else {
                        dp[v][0].second += dp[u][1].second;
                    }
                }
            }
        }
    })(0, -1);
    dbg(dp);
    vector<bool> good(n), vis(n);
    if(dp[0][0].first != dp[0][1].first) {
        good[0] = dp[0][1].first > dp[0][0].first;
    } else {
        good[0] = dp[0][0].second > dp[0][1].second;
    }
    y_combinator([&](auto dfs, int v, bool is_good) -> void {
        vis[v] = 1; good[v] = is_good;
        for (auto &u : adj[v]) {
            if(!vis[u]) {
                if(is_good) dfs(u, 0);
                else {
                    if(dp[u][0].first != dp[u][1].first) {
                        good[u] = dp[u][1].first > dp[u][0].first;
                    } else {
                        good[u] = dp[u][0].second > dp[u][1].second;
                    }
                    dfs(u, good[u]);
                }
            }
        }
    })(0, good[0]);
    dbg(good);

    // if(good[0]) cout << dp[0][1].first << " " << dp[0][1].second << '\n';
    // else cout << dp[0][0].first << " " << dp[0][0].second << '\n';
    int w = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        if(good[i]) w++, sum += (int)adj[i].size();
    }
    cout << w << " " << sum + (n - w) << '\n';

    for (int i = 0; i < n; i++) {
        cout << (good[i] ? (int)adj[i].size() : 1) << " \n"[i == n - 1];
    }
    return 0;
}