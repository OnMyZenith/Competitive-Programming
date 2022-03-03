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

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }



void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &u : a) {
        cin >> u;
    }
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    ll diff = 1e18, curr = 0, ans = -1;
    for (int i = 0; i < n; i++) {
        curr += a[i];
        if(ckmin(diff, abs(sum - 2 * curr))) ans = i + 1;
    }
    cout << max(accumulate(a.begin(), a.begin()+ ans, 0LL), accumulate(a.begin() + ans, a.end(), 0LL)) << '\n';




}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}