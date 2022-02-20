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


int main() {
    vamos;
    int n, mx = 0; cin >> n;
    vector<string> s(n);
    for (auto &u : s) {
        cin >> u;
        mx = max(mx, (int)u.size());
    }
    vector<set<int>> g(26);
    for (int i = 0; i < n - 1; i++) {
        string s1 = s[i], s2 = s[i + 1];
        int m = max((int)s1.size(), (int)s2.size());
        for (int j = 0; j < m; j++) {
            if(j == (int)s1.size()) break;
            if(j == (int)s2.size()) {
                cout << "Impossible\n";
                return 0;
            }
            if(s1[j] == s2[j]) continue;
            g[s1[j] - 'a'].insert(s2[j] - 'a');
            break;
        }
    }
    vector<bool> vis(26);
    vector<vector<int>> x;
    vector<int> temp;
    auto dfs = y_combinator([&](auto self, int v)->bool{
        vis[v] = 1;
        temp.push_back(v);
        for (auto u = g[v].begin(); u != g[v].end(); u++) {
            if(vis[*u]) return false;
            self(*u);
        }
        return true;
    });
    for (int i = 0; i < 26; i++) {
        if(!vis[i]){
            temp.clear();
            if(!dfs(i)){
                cout << "Impossible\n";
                return 0;
            }
            x.push_back(temp);
        }
    }
    fill(vis.begin(), vis.end(), false);
    for (auto &gp : x) {
        for (auto &c : gp) {
            vis[c] = 1;
            cout << char('a' + c);
        }
    }
    for (int i = 0; i < 26; i++) {
        if(!vis[i]) cout << char('a' + i);
    }
    cout << '\n';
    return 0;
}