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
using ld = long double;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    ll n, m, k; cin >> n >> m >> k;
    vector<pair<ld, int>> mini(m, {4e18, 1e9}); mini[0] = {0, 0};

    long double res = 0, sum = 0;
    for (int i = 0, num; i < n; i++) {
        cin >> num;
        sum += (long double)num - (long double)k / m;
        for (int j = 0; j < m; j++) {
            int cnt = int((m - (i + 1 - mini[j].second) % m) % m);
            ckmax(res, (sum - mini[j].first) - (ld)k * cnt / m);
            dbg(res, i, mini[j], sum);
        }
        ckmin(mini[(i + 1) % m], {sum, i + 1});
    }
    if (abs(res - (ll)res) < abs(res - ll(ceil(res)))) cout << ll(res) << '\n';
    else cout << ll(ceil(res)) << '\n';

    return 0;
}