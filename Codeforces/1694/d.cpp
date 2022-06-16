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

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int pp; cin >> pp; pp--;
        adj[pp].push_back(i);
    }
    vector<pair<ll, ll>> range(n);
    for (int i = 0; i < n; i++) {
        cin >> range[i].first >> range[i].second;
    }

    cout << y_combinator([&](auto dfs, int v) -> pair<ll, ll> {
        pair<ll, ll> cost_sum;
        ll sum = 0, cnt = 0;
        for (auto &u : adj[v]) {
            pair<ll, ll> one = dfs(u);
            cnt += one.first;
            sum += one.second;
        }
        ckmin(sum, range[v].second);
        cost_sum = {cnt, sum};
        if (sum < range[v].first) {
            cost_sum.second = range[v].second;
            cost_sum.first++;
        }
        return cost_sum;
    })(0).first << '\n';
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