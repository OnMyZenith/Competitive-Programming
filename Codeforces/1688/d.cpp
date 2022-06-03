/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

void solve() {
    ll n, k; cin >> n >> k;
    vector<int> a(n);
    vector<ll> pre(n + 1);
    ll K = k;
    k = min(n, K);
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
        if(i + 1 >= k) {
            ckmax(mx, pre[i + 1] - pre[i + 1 - k]);
        }
    }
    if(n == 1) {
        cout << mx + K - 1 << '\n';
        return;
    } 
    ll extra = 0;
    if(K > n) {
        for (ll s = 0; s < n; s++) {
            ll one = s * (s - 1) / 2;
            ll two = 0;
            ll left = K - s;
            if (left >= s + 1) {
                two += s + s * (s + 1);
                left -= s + 1;
            } else {
                two += s + (left - 1) * (left);
                left = 0;
            }
            if(left) {
                ll cnt = left;
                if(cnt > n - (s + 1)) cnt = n - (s + 1), left -= n - (s + 1);
                else left = 0;
                two += cnt * (cnt + 1) / 2 + 2 * s * cnt;
            }
            ll three = 0;
            if(left) {
                ll q = left / (n - 1);
                ll r = left % (n - 1);
                three += q * n * (n - 1);
                three += r * (r + 1);
            }
            dbg(one, two, extra);

            ckmax(extra, one + two + three);
        }
    } else {
        extra = K * (K - 1) / 2;
    }
    cout << mx + extra << '\n';
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