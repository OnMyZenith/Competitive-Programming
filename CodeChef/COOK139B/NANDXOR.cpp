/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

constexpr int pct(int x) { return __builtin_popcount(x); }                                  // # of bits set
constexpr int log_2(int x) { return x ? (8 * (int)sizeof(x)) - 1 - __builtin_clz(x) : -1; } // Floor of log_2(x); index of highest 1-bit
constexpr int next_pow_2(int x) { return x > 0 ? 1 << log_2(2 * x - 1) : 0; }               // 16->16, 13->16, (x<=0)->0
constexpr int log_2_ceil(int x) { return log_2(x) + int(__builtin_popcount(x) != 1); }      // Ceil of log_2(x);

template <typename T_vector> void ov(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    if(pct(a[i] ^ a[j]) == pct(a[k] ^ a[l])) {
                        cout << i + 1 << " " << j + 1 << " " << k + 1 << " " << l + 1 << '\n';
                        return;
                    }
                    if(pct(a[i] ^ a[k]) == pct(a[j] ^ a[l])) {
                        cout << i + 1 << " " << k + 1 << " " << j + 1 << " " << l + 1 << '\n';
                        return;
                    }
                    if(pct(a[i] ^ a[l]) == pct(a[k] ^ a[j])) {
                        cout << i + 1 << " " << l + 1 << " " << k + 1 << " " << j + 1 << '\n';
                        return;
                    }
                }
            }
        }
    }

    // vector<set<int>> idx(31);
    // for (int i = 0; i < n; i++) {
    //     for (int j = i + 1; j < n; j++) {
    //         int x = pct(a[i] ^ a[j]);
    //         idx[x].insert(i);
    //         idx[x].insert(j);
    //         if((int)idx[x].size() >= 4) {
    //             vector<int> res;
    //             auto it = idx[x].begin();
    //             for (int cnt = 0; cnt < 4; cnt++, it++) {
    //                 res.push_back(*it);
    //             }
    //             while(pct(a[res[0]] ^ a[res[1]]) != pct(a[res[2]] ^ a[res[3]])){
    //                 next_permutation(res.begin(), res.end());
    //             }
    //             ov(res, 1);
    //             return;
    //         }
    //     }
    // }
    cout << "-1\n";
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}