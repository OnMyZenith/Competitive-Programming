/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

const int __ = 1e6 + 007;  // 1e6 + 007 => int arr =   4 MB, ll arr =   8 MB
const int _ = 2e5 + 007;   // 2e5 + 007 => int arr = 0.8 MB, ll arr = 1.6 MB

int N = 1;
int a[3 * __];

// idx is 0 based
void set(int idx, int x) {
    for (a[idx += N] = x; idx >>= 1;)
        a[idx] = a[idx << 1] + a[idx << 1 | 1];
}

// idx is 0 based
void add(int idx, int x) {
    for (a[idx += N] += x; idx >>= 1;)
        a[idx] = a[idx << 1] + a[idx << 1 | 1];
}

// [l, r) Half-Intervals
int query(int l, int r) {
    int lv = 0, rv = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) lv = lv + a[l++];
        if (r & 1) rv = rv + a[--r];
    }
    return lv + rv;
}


// Check result <= hi
template <class T, class U> T ft(T lo, T hi, U f) {
    ++hi, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo) / 2;
        f(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n, q; cin >> n >> q;
    while (N < n) N <<= 1;

    for (int i = 0, x; i < n; i++) cin >> x, --x, a[N + x]++;
    for (int i = N; --i;) a[i] = a[i << 1] + a[i << 1 | 1];

    while (q--) {
        int k; cin >> k;
        if (k > 0) {
            k--;
            add(k, 1);
        }
        else {
            k = -k;
            int idx = 1;
            while (idx < N) {
                if(a[idx << 1] >= k) idx <<= 1;
                else {
                    k -= a[idx << 1];
                    idx = 2 * idx + 1;
                }
            }
            add(idx - N, -1);
        }
    }
    int idx = ft(0, n - 1, [&](int id) -> bool {
        return query(0, id + 1) > 0;
    });
    cout << (query(idx, idx + 1) ? idx + 1 : 0) << '\n';
    return 0;
}