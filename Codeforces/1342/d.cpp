/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

template <typename T_vector> void ov(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}

// Because multiset.erase(t) will erase all occurances of t!!
template <class T, class U> bool erase(T &t, const U &u) {
    auto it = t.find(u);
    if (it == end(t)) return false;
    t.erase(it); return true;
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

    int n, k; cin >> n >> k;
    vector<int> a(n), lim(k);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < k; i++) cin >> lim[i];

    sort(a.rbegin(), a.rend());
    int optimal = ft(1, n, [&](int tot) -> bool {
        vector<int> sets(tot);
        for (int i = 0, j = 0; i < n; i++) {
            if (lim[a[i] - 1] - sets[j] <= 0) return false;
            sets[j++]++;
            if (j >= tot) j -= tot;
        }
        return true;
    });
    
    vector<vector<int>> res(optimal);
    for (int i = 0, j = 0; i < n; i++) {
        res[j++].push_back(a[i]);
        if (j >= optimal) j -= optimal;
    }
    cout << (int)res.size() << '\n';
    for (auto &v : res) {
        cout << (int)v.size() << " ";
        ov(v);
    }
    return 0;
}