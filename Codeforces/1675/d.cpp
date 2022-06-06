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

template <typename T_vector> void ov(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}


void solve() {
    int n; cin >> n;
    vector<int> p(n);
    vector<vector<int>> adj(n);
    int s = -1;
    for (int i = 0; i < n; i++) {
        cin >> p[i]; p[i]--;
        if (i == p[i]) {
            s = i;
            continue;
        } else adj[p[i]].push_back(i);
    }
    assert(s != -1);
    vector<vector<int>> all;
    vector<int> curr;
    y_combinator([&](auto self, int v) -> void {
        curr.push_back(v);
        for (auto &u : adj[v]) {
            self(u);
        }
        if(curr.size()) all.push_back(curr), curr.clear();
    })(s);
    cout << '\n';
    cout << (int)all.size() << '\n';
    for (auto &thing : all) {
        cout << (int)thing.size() << '\n';
        ov(thing, 1);
    }
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