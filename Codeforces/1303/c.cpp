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
    string s; cin >> s;
    int n = (int)s.size();
    map<char, set<char>> mp;
    for (int i = 0; i < n - 1; i++) {
        mp[s[i]].insert(s[i + 1]);
        mp[s[i + 1]].insert(s[i]);
    }
    vector<int> vis(26);
    auto found_cycle = y_combinator([&](auto self, char v, char p) -> bool {
        vis[v - 'a'] = 1;
        if((int)mp[v].size() > 2) return 1;
        for (auto &u : mp[v]) {
            if (u != p) {
                if (vis[u - 'a']) return 1;
                else if (self(u, v)) return 1;
            }
        }
        return 0;
    });

    for (auto &[c, fam] : mp) {
        if (!vis[c - 'a'] && found_cycle(c, -1)) {
            cout << "NO\n";
            return;
        }
    }

    vector<vector<char>> res;
    vector<char> curr;
    set<char> seen;
    auto create = y_combinator([&](auto self, char v, char p) -> bool {
        seen.insert(v);
        curr.push_back(v);
        for (auto &u : mp[v]) {
            if (u != p) {
                self(u, v);
            }
        }
        return 0;
    });

    for (auto &[c, fam] : mp) {
        if(!seen.count(c) && (int)fam.size() <= 1) {
            curr.clear();
            create(c, -1);
            res.push_back(curr);
        }
    }
    dbg(res);
    string fin;
    for (auto &ff : res) {
        for (auto &c : ff) {
            fin += c;
        }
    }

    for (int i = 0; i < 26; i++) if (!seen.count(char(i + 'a'))) fin += char(i + 'a');

    cout << "YES\n";
    cout << fin << '\n';
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