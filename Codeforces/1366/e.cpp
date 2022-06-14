/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


template <typename T, bool maximum_mode = false>
struct RMQ {
    static int highest_bit(unsigned x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    int n = 0;
    vector<T> values;
    vector<vector<int>> range_low;

    RMQ(const vector<T> &_values = {}) {
        if (!_values.empty())
            build(_values);
    }

    // Note: when `values[a] == values[b]`, returns b.
    int better_index(int a, int b) const {
        return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
    }

    void build(const vector<T> &_values) {
        values = _values;
        n = int(values.size());
        int levels = highest_bit(n) + 1;
        range_low.resize(levels);

        for (int k = 0; k < levels; k++)
            range_low[k].resize(n - (1 << k) + 1);

        for (int i = 0; i < n; i++)
            range_low[0][i] = i;

        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_low[k][i] = better_index(range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
    }

    // Note: breaks ties by choosing the largest index.
    int query_index(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = highest_bit(b - a);
        return better_index(range_low[level][a], range_low[level][b - (1 << level)]);
    }

    T query_value(int a, int b) const {
        return values[query_index(a, b)];
    }
};

const int MOD = 998244353;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    RMQ<int> seg(a);
    if(seg.query_value(0, n) != b[0] || m > n) {
        cout << "0\n";
        return 0;
    }
    ll ans = 1;
    for (int i = 1; i < m; i++) {

        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            seg.query_value(n - 1 - mid, n) >= b[i] ? lo = mid : hi = mid - 1;
        }
        assert(lo != n);
        int l1 = n - 1 - lo;
        
        lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            seg.query_value(n - 1 - mid, n) <= b[i] ? hi = mid : lo = mid + 1;
        }
        int l2 = n - 1 - lo;

        if(l1 > l2 || seg.query_value(l1, n) != b[i]) {
            cout << "0\n";
            return 0;
        }

        ans *= l2 - l1 + 1;
        ans %= MOD;
    }
    cout << ans << '\n';

    return 0;
}