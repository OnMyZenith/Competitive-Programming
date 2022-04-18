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

template <class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template <class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

template <typename T_vector> void ov(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}

int main() {
    vamos;

    int n, m, s; cin >> n >> m >> s; s--;
    auto adj = reG(n, m);
    vector<int> p(n, -1);
    int t = -1, sec_p = -1;
    for (auto &ss : adj[s]) {
        // adj[ss].erase(find(adj[ss].begin(), adj[ss].end(), s));
        vector<bool> vis(n);
        vis[ss] = 1;
        vis[s] = 1;
        dbg(ss);
        y_combinator([&](auto dfs, int v, int _p)->void{
            if(p[v] != -1) {
                t = v;
                sec_p = _p;
                return;
            }
            p[v] = _p;
            for (auto &u : adj[v]) {
                if(!vis[u]) {
                    vis[u] = 1;
                    dfs(u, v);
                    if(t != -1) return;
                }
            }
        })(ss, s);
        if(t != -1) break;
    }
    dbg(t);
    if(t == -1) {
        cout << "Impossible\n";
    } else {
        vector<int> path1 = {t}, path2 = {t, sec_p};
        int i = t, j = sec_p;
        dbg(sec_p);
        while(i != -1 && i != s && p[i] != s) {
            path1.push_back(p[i]); i = p[i];
        }
        if(path1.back() != s) path1.push_back(s);
        while(j != -1 && j != s && p[j] != s) {
            path2.push_back(p[j]); j = p[j];
        }
        if(path2.back() != s) path2.push_back(s);
        reverse(path1.begin(), path1.end());
        reverse(path2.begin(), path2.end());
        cout << "Possible\n";
        cout << (int)path1.size() << '\n';
        ov(path1, 1);
        cout << (int)path2.size() << '\n';
        ov(path2, 1);
    }
    return 0;
}