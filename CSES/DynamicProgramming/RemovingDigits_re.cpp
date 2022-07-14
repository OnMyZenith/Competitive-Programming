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

const int N = 1e6 + 7;
int dp[N];

int ans(int n) {
    if (n == 0) return 0;
    assert(n > 0);
    int &ret = dp[n];
    if (ret != -1) return ret;
    ret = n;
    string tmp = to_string(n);
    int rem = *max_element(tmp.begin(), tmp.end()) - '0';
    ckmin(ret, ans(n - rem) + 1);
    return ret;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n; cin >> n;
    memset(dp, -1, (n + 1) * sizeof(int));
    cout << ans(n) << '\n';

    return 0;
}
