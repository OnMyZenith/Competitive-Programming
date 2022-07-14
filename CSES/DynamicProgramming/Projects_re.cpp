/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n; cin >> n;
    struct Project {
        int l, r, p;
        bool operator<(const Project &other) const {
            return this->r < other.r;
        }
    };

    vector<Project> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r >> a[i].p;
    }
    sort(a.begin(), a.end());

    vector<ll> dp(n);
    for (int i = 0; i < n; i++) {
        int lo = -1, hi = i - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (a[mid].r < a[i].l) lo = mid;
            else hi = mid - 1;
        }
        if (i) dp[i] = dp[i - 1];
        ckmax(dp[i], (lo >= 0 ? dp[lo] : 0) + a[i].p);
    }
    cout << dp[n - 1] << '\n';
    return 0;
}
