/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

template <class T> using pqdec = std::priority_queue<T>;
template <class T> using pqinc = std::priority_queue<T, vector<T>, greater<T>>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n, k; cin >> n >> k;
    vector<int> a(n);
    vector<ll> suff(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = suff[i + 1] + a[i];
    }
    ll ans = suff[0];
    suff[0] = -4e18, suff[n] = -4e18;
    sort(suff.rbegin(), suff.rend());
    dbg(suff);
    cout << ans + accumulate(suff.begin(), suff.begin() + k - 1, 0ll) << '\n';

    return 0;
}