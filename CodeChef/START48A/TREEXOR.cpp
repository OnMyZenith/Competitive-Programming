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
    int n, k; cin >> n >> k;
    vector<vector<int>> children(n);
    for (int i = 1; i < n; i++) {
        int p; cin >> p;
        children[--p].push_back(i);
    }
    vector<int> size(n);
    y_combinator([&](auto self, int v) -> void {
        size[v] = 1;
        for (auto &u : children[v]) {
            self(u);
            size[v] += size[u];
        }
    })(0);

    vector<bool> xor_v(n);
    y_combinator([&](auto self, int v, int need) -> void {

        if (need) need--, xor_v[v] = 1;
        else return;

        for (auto &u : children[v]) {
            self(u, min(need, size[u]));
            need -= min(need, size[u]);
        }

    })(0, k);

    vector<bool> a(n);
    y_combinator([&](auto self, int v) -> void {
        a[v] = xor_v[v];
        for (auto &u : children[v]) {
            self(u);
            a[v] = a[v] ^ xor_v[u];
        }
    })(0);
    for (int i = 0; i < n; i++) cout << a[i];
    cout << '\n';
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
