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
    vector<pair<int, int>> a(n);
    bool poss = 1;
    vector<set<int>> adj(n), pos(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        poss &= a[i].first != a[i].second;
        a[i].first--, --a[i].second;

        pos[a[i].first].insert(i);
        pos[a[i].second].insert(i);
    }
    for (int i = 0; i < n; i++) {
        if ((int)pos[i].size() != 2) {
            poss = 0;
            break;
        }
        adj[*pos[i].begin()].insert(*pos[i].rbegin());
        adj[*pos[i].rbegin()].insert(*pos[i].begin());
    }
    dbg(adj);
    
    if (!poss) {
        cout << "NO\n";
        return;
    }

    vector<int> color(n);
    for (int i = 0; i < n && poss; i++) {
        if (!color[i]) {
            queue<int> q; q.push(i);
            color[i] = 1;
            while (!q.empty()) {
                int v = q.front(); q.pop();
                for (auto &u : adj[v]) {
                    if (!color[u]) {
                        color[u] = (color[v] == 1 ? 2 : 1);
                        q.push(u);
                    } else if (color[u] == color[v]) {
                        poss = 0;
                        break;
                    }
                }
            }
        }
    }
    cout << (poss ? "YES" : "NO") << '\n';
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