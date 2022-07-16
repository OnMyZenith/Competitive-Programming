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
    int n; cin >> n;
    deque<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int _cnt = 0;
    while ((int)a.size() > 1 && a.front() == 0) _cnt++, a.pop_front();

    cout << y_combinator([&](auto self, int c0) -> ll {
        if ((int)a.size() == 1) return a.front();
        
        if (c0 > 0) a.push_front(0);

        for (int i = (int)a.size() - 1; i > 0; i--) a[i] -= a[i - 1];
        a.pop_front();

        sort(a.begin(), a.end());

        int cnt = 0;
        while ((int)a.size() > 1 && a.front() == 0)
            a.pop_front(), cnt++;

        return self(cnt + max(c0 - 1, 0));
    })(_cnt) << '\n';
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
