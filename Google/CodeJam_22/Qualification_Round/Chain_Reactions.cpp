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

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }


void solve(int _TC) {
    int n; cin >> n;
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) cin >> f[i];
    vector<vector<int>> children(n + 1);
    vector<int> minv(n + 1, 1e9), par(n + 1);
    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        children[p].push_back(i);
        par[i] = p;
    }
    // vector<bool> vis(n + 1);
    // auto maximize = y_combinator([&](auto dfs, int v) -> void {
    //     vis[v] = 1;
    //     if((int)children[par[v]].size() == 1 && v && par[v]) {
    //         dbg(v, par[v]);
    //         ckmax(f[v], f[par[v]]);
    //         ckmax(f[par[v]], f[v]);
    //     }
    //     for (auto &u : children[v]) {
    //         dfs(u);
    //     }
    // });
    // for (int i = 0; i <= n; i++) if(!vis[i]) maximize(i);
    // dbg(f);
    for (int i = 1; i <= n; i++) {
        int v = i;
        if(!children[v].empty()) continue;
        int curr = f[v];
        ckmin(minv[v], curr);
        while(par[v] != 0) {
            v = par[v];
            ckmin(curr, f[v]);
            // if(!ckmin(minv[v], curr)) break;
            ckmin(minv[v], curr);
        }
    }

    minv[0] = 0;
    for (int i = 0; i <= n; i++) {
        sort(children[i].begin(), children[i].end(), [&](int c1, int c2){return minv[c1] < minv[c2];});
    }
    dbg(minv);
    ll ans = 0;
    y_combinator([&](auto dfs, int v, int mx) -> void {
        ckmax(mx, f[v]);
        // dbg(v);
        if(children[v].empty()) {
            ans += mx;
        } else {
            bool fi = 1;
            for (auto &c : children[v]) {
                if(fi) dfs(c, mx), fi = 0;
                else dfs(c, 0);
            }
        }
    })(0, 0);
    cout << "Case #" << _TC << ": ";
    cout << ans << '\n';
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