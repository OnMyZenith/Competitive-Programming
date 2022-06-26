/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


void solve() {
    int n, m, k; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> k;
    vector<int> b(k);
    for (int i = 0; i < k; i++) cin >> b[i];

    if (accumulate(a.begin(), a.end(), 0ll) != accumulate(b.begin(), b.end(), 0ll)) {
        cout << "No\n";
        return;
    }

    vector<pair<ll, ll>> res;
    for (int i = 0; i < n; i++) {
        ll cnt = 1;
        while (a[i] % m == 0) a[i] /= m, cnt *= m;
        if (res.empty() || res.back().first != a[i]) res.push_back({a[i], cnt});
        else res.back().second += cnt;
    }
    int i = 0, j = 0;
    bool fail = 0;
    dbg(res);
    for (; j < k && i < (int)res.size(); j++) {
        if (b[j] < res[i].first) {
            fail = 1;
            break;
        } else if (b[j] == res[i].first) {
            if(--res[i].second == 0) i++;
        } else {
            if (b[j] % res[i].first) {
                fail = 1;
                break;
            }
            ll need = b[j] / res[i].first;
            if (need > res[i].second) {
                fail = 1;
                break;
            }
            // dbg(need);
            while (need != 1) {
                if (need % m) {
                    fail = 1;
                    dbg(need, m);
                    break;
                } else {
                    need /= m;
                }
            }
            res[i].second -= b[j] / res[i].first;
            if (res[i].second == 0) i++;
        }
        // dbg(i, j);
        // dbg(res);
        // dbg(fail);
    }
    // dbg(res, i, j);
    if (i != (int)res.size() || j != k) fail = 1;
    cout << (fail ? "No" : "Yes") << '\n';

    // int i = 0, j = 0;
    // ll sa = 0, sb = 0;
    // while (i < n && j < k) {
    //     if (a[i] == b[j]) {
    //         assert(!sa && !sb);
    //         i++, j++;
    //         continue;
    //     }

    //     if (a[i] < b[j]) {
    //         do {
    //             for (int l = 0; l < m; l++) {
    //                 if (l + i >= n || a[i] != a[l + i]) {
    //                     fail = 1;
    //                     break;
    //                 }
    //                 sa += a[l];
    //             }
    //         } while (sa < b[j]);
    //         if (sa > b[j]) fail = 1;
    //         if (fail) break;
    //         sa = 0, sb = 0;
    //     } else {
    //         do {
    //             for (int l = 0; l < m; l++) {
    //                 if (l + j >= k || b[j] != b[l + j]) {
    //                     fail = 1;
    //                     break;
    //                 }
    //                 sb += b[l];
    //             }
    //         } while (sb < b[j]);
    //         if (sb > b[j]) fail = 1;
    //         if (fail) break;
    //         sa = 0, sb = 0;
    //     }

    // }




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