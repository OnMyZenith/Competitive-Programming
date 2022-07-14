/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

const int inf = 1e6;
const int N = 507;
int dp[N][N];

int sol(int a, int b) {
    if (a == b) return 0;

    if (a > b) swap(a, b);

    int &ret = dp[a][b];
    if (ret != -1) return ret;

    if (a == 1) return ret = b - 1;

    ret = inf;
    for (int len = 1; len <= b / 2; len++) {
        ret = min(ret, 1 + sol(a, len) + sol(a, b - len));
    }

    for (int len = 1; len <= a; len++) {
        ret = min(ret, 1 + sol(b, len) + sol(b, a - len));
    }

    return ret;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    memset(dp, -1, sizeof(dp));
    int a, b; cin >> a >> b;
    cout << sol(a, b) << '\n';

    return 0;
}
