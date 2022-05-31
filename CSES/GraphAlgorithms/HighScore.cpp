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


template <class T> using pqdec = std::priority_queue<T>;
template <class T> using pqinc = std::priority_queue<T, vector<T>, greater<T>>;
template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }


int main() {
    vamos;

    int n, m; cin >> n >> m;
    vector<set<pair<int, int>>> adj(n), adjb(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        int x; cin >> x;
        // assert(a != b);
        auto it = adj[a].lower_bound({b, -2e9});
        if (it != adj[a].end() && it->first == b){
            if (it->second < x){
                adj[a].erase(it);
                adj[a].insert({b, x});
            }
        } else adj[a].insert({b, x});

        swap(a, b);
        it = adjb[a].lower_bound({b, -2e9});
        if (it != adjb[a].end() && it->first == b){
            if (it->second < x){
                adjb[a].erase(it);
                adjb[a].insert({b, x});
            }
        } else adjb[a].insert({b, x});
    }

    vector<int> val(n), val2(n);
    y_combinator([&](auto self, int v) -> void {
        val[v] = 1;
        for (auto &u : adjb[v]) {
            if(!val[u.first]) self(u.first);
        }
    })(n - 1);
    y_combinator([&](auto self, int v) -> void {
        val2[v] = 1;
        for (auto &u : adj[v]) {
            if(!val2[u.first]) self(u.first);
        }
    })(0);
    for (int i = 0; i < n; i++) val[i] = val[i] && val2[i];
    
    dbg(val);
    // only for stress tests
    if(!val[0]) {
        cout << "-1\n";
        return 0;
    }

    vector<array<int, 3>> edges;
    for (int i = 0; i < n; i++) {
        if(!val[i]) continue;
        for (auto &[v, w] : adj[i]) {
            if(val[v]) edges.push_back({i, v, w});
        }
    }

    vector<ll> d(n, -4e18);

    bool done = 0;
    for (int i = 0; i < n; i++) {
        done = 0;
        for (auto &[v, u, w] : edges) {
            done |= ckmax(d[u], d[v] + w);
        }
    }
    if(done) {
        cout << "-1\n";
        return 0;
    }

    // dbg(adj);
    // for (auto &v : adj) {
    //     dbg(v);
    // }

    vector<ll> dis(n, -4e18); dis[0] = 0;
    pqdec<pair<ll, int>> Q; Q.push({0, 0});
    set<int> ok;
    while(!Q.empty()) {
        auto [d_v, v] = Q.top(); Q.pop();

        if(d_v < dis[v]) continue;

        for (auto [u, w] : adj[v]) {
            if (val[u] && ckmax(dis[u], d_v + w)) {
                Q.push({dis[u], u});
            }
        }
    }
    cout << (dis[n - 1] == -(ll)4e18 ? -1 : dis[n - 1]) << '\n';

    return 0;
}
