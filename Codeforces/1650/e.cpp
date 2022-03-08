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

template <class T>
bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T>
bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

void solve() {
    int n, d; cin >> n >> d;
    vector<int> a(n), b;
    for (auto &u : a) {
        cin >> u;
    }
    b = a;
    vector<int> rest(n);
    auto cal_rest = [&]() {
        rest.resize(n);
        rest[0] = a[0] - 1;
        for (int i = 1; i < n; i++) {
            rest[i] = a[i] - a[i - 1] - 1;
        }
    };
    cal_rest();
    int ans = *min_element(rest.begin(), rest.end());

    auto res = [&](int i) -> void {
        a = b;
        if(i < 0) return;
        a.erase(a.begin() + i);
        n = (int)a.size();
        cal_rest();
        sort(rest.begin(), rest.end());
        // dbg(rest);
        int a1 = ans;
        ckmax(a1, rest[n - 1] / 2 - !(rest[n - 1] & 1));
        ckmax(a1, d - a[n - 1] - 1);
        ckmin(a1, rest[0]);
        ckmax(ans, a1);
    };

    a = b; cal_rest();
    // dbg(rest);
    int idx_w = 0, worst = rest[0];
    for (int i = 1; i < n; i++) {
        if (ckmin(worst, rest[i])) idx_w = i;
    }
    // dbg(idx_w);

    res(idx_w); res(idx_w - 1);
    cout << ans << '\n';
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    while (TT--) {
        solve();
    }

    return 0;
}