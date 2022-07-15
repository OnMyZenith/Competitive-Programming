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
    ll n, c, q; cin >> n >> c >> q;
    string s; cin >> s;
    vector<pair<ll, ll>> copy(c);
    vector<ll> cnt(c + 1);
    cnt[0] = n;
    for (ll i = 0, l, r; i < c; i++) {
        cin >> l >> r;
        --l, --r;
        copy[i] = {l, r};
        cnt[i + 1] = cnt[i] + r - l + 1;
    }
    while (q--) {
        ll K; cin >> K;
        cout << y_combinator([&](auto self, ll k) -> char {
            dbg(k);
            int i = int(lower_bound(cnt.begin(), cnt.end(), k) - cnt.begin());
            dbg(i, k);
            if (i) dbg(i, k, copy[i - 1].first, k, cnt[i - 1]);
            if (i) return self(copy[i - 1].first + k - cnt[i - 1]);
            else return s[k - 1];
        })(K) << '\n';
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
