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
    vector<pair<int, int>> seg(2);
    for (int i = 0; i < 2; i++) cin >> seg[i].first >> seg[i].second;

    if(seg[1] < seg[0]) swap(seg[1], seg[0]);
    int l1 = seg[0].first;
    int r1 = seg[0].second;
    int l2 = seg[1].first;
    int r2 = seg[1].second;

    int cost_matching = max(l2 - r1, 0);
    int max_taken = max(min(r1 - l2, r2 - l2), 0);
    int extremes_seg = max(r2 - l1, r1 - l1);

    if (k < (ll)max_taken * n) {
        cout << "0\n";
        return;
    }
    k -= max_taken * n;
    extremes_seg -= max_taken;
    cout << y_combinator([&](auto self, int num, int req) -> int {
        if (num == 0) return 2e9;

        if (extremes_seg >= req) {
            return cost_matching + req;
        }

        return cost_matching + extremes_seg + min(2 * (req - (extremes_seg)), self(num - 1, req - (extremes_seg)));
    })(n, k) << '\n';

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