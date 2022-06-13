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
template <class T> using pqdec = std::priority_queue<T>;
template <class T> using pqinc = std::priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n; cin >> n;
    vector<int> a(n), d(n);
    vector<ll> oddsumupto(n), evensumupto(n);
    ll best = 0, sum = 0;
    pqdec<ll> q1, q2; q1.push(0); q2.push(0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        oddsumupto[i] = (i ? oddsumupto[i - 1] : 0);
        evensumupto[i] = (i ? evensumupto[i - 1] : 0);
        sum += i & 1 ? 0 : a[i];
        if (i & 1) {
            oddsumupto[i] += a[i];
            q1.push(evensumupto[i] - oddsumupto[i]);
            ckmin(best, evensumupto[i] - oddsumupto[i] - q1.top());
        } else {
            evensumupto[i] += a[i];
            q2.push(evensumupto[i] - oddsumupto[i]);
            ckmin(best, evensumupto[i] - oddsumupto[i] - q2.top());
        }
    }
    cout << sum - best << '\n';
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