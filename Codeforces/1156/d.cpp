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

struct union_find {
    vector<int> parent;
    vector<int> size;
    int components = 0;

    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        size.assign(n + 1, 1);
        components = n;
    }

    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (size[x] < size[y])
            swap(x, y);

        parent[y] = x;
        size[x] += size[y];
        components--;
        return true;
    }
};


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n; cin >> n;
    vector<vector<array<int, 2>>> adj(n);
    for (int i = 1, u, v , t; i < n; i++) {
        cin >> u >> v >> t;
        u--, v--;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }

    vector<bool> vis0(n), vis1(n);
    union_find u0(n);
    union_find u1(n);
    auto dfs = y_combinator([&](auto self, int v, int p, bool t1) -> void {
        if (p == -1) {
            vis0[v] = vis1[v] = 1;
        } else if (t1) {
            vis1[v] = 1;
            u1.unite(v, p);
        } else {
            vis0[v] = 1;
            u0.unite(v, p);
        }

        for (auto &[u, t] : adj[v]) {
            if (p == -1) {
                if (t == 1 && !vis1[u]) self(u, v, t);
                else if (t == 0 && !vis0[u]) self(u, v, t);
            } else if (u != p && t == t1)
                self(u, v, t);
        }
    });
    for (int i = 0; i < n; i++) {
        if (!vis0[i] || !vis1[i]) {
            dfs(i, -1, 0);
        }
    }

    ll ans = 0;
    set<int> done0, done1;
    for (int i = 0; i < n; i++) {
        int p = u0.find(i);
        if (!done0.count(p)) {
            done0.insert(p);
            ll siz = u0.size[p];
            ans += siz * (siz - 1);
        }
        p = u1.find(i);
        if (!done1.count(p)) {
            done1.insert(p);
            ll siz = u1.size[p];
            ans += siz * (siz - 1);
        }
    }
    dbg(ans);
    set<pair<int, int>> done2;
    fill(vis0.begin(), vis0.end(), 0);
    auto cnt_0_1 = y_combinator([&](auto self, int v, int p, bool t1) -> void {
        for (auto &[u, t] : adj[v]) {
            if (p == -1) {
                dbg(u, v);
                self(u, v, t);
            } else {
                if (u != p) {
                    if (t1 == 0 && t == 1) {
                        int p1 = u0.find(v);
                        int p2 = u1.find(v);
                        if (!done2.count({min(p1, p2), max(p1, p2)})) {
                            ll sz0 = u0.size[p1];
                            ll sz1 = u1.size[p2];
                            dbg(p, u);
                            ans += (sz0 - 1) * (sz1 - 1);
                            done2.insert({min(p1, p2), max(p1, p2)});
                        }
                    } else if (t1 == 1 && t == 0) {
                        int p1 = u0.find(v);
                        int p2 = u1.find(v);
                        if (!done2.count({min(p1, p2), max(p1, p2)})) {
                            ll sz0 = u0.size[p1];
                            ll sz1 = u1.size[p2];
                            ans += (sz0 - 1) * (sz1 - 1);
                            done2.insert({min(p1, p2), max(p1, p2)});
                        }
                    }
                    self(u, v, t);
                }
            }
        }



        // if (t1) return; 
        // vis0[v] = 1;

        // for (auto &[u, t2] : adj[v]) {
        //     dbg(t2, p, t2 && p != -1);
        //     if (u == p) continue;
        //     else if (p == -1) {
        //         if (t2 == 0 && !vis0[u]) self(u, v, 0);
        //         continue;
        //     }
        //     if (t2 == 0) self(u, v, 0);
        //     else if (t2 == 1) {
        //         int p1 = u0.find(p);
        //         int p2 = u1.find(u);
        //         if (!done2.count({min(p1, p2), max(p1, p2)})) {
        //             ll sz0 = u0.size[p1];
        //             ll sz1 = u1.size[p2];
        //             dbg(p, u);
        //             ans += (sz0 - 1) * (sz1 - 1);
        //             done2.insert({min(p1, p2), max(p1, p2)});
        //         }
        //     }
        // }
    });

    // for (int i = 0; i < n; i++) {
    //     for (auto &[v, t1] : adj[i]) {
    //         if (t1) continue;
    //         for (auto &[u, t2] : adj[v]) {
    //             if (!t2) continue;
    //             int p1 = u0.find(i);
    //             int p2 = u1.find(u);
    //             if (!done2.count({min(p1, p2), max(p1, p2)})) {
    //                 ll sz0 = u0.size[p1];
    //                 ll sz1 = u1.size[p2];
    //                 ans += (sz0 - 1) * (sz1 - 1);
    //                 done2.insert({min(p1, p2), max(p1, p2)});
    //             }
    //         }
    //     }
    // }
    for (int i = 0; i < n; i++) {
        if ((int)adj[i].size() == 1) {
            cnt_0_1(i, -1, 0);
            break;
        }
    }
    cout << ans << '\n';

    return 0;
}