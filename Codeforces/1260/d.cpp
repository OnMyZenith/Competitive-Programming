/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifndef asr_debug
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("Ofast")
// Can casuse floating point errors, assumes associativeness for instance

#pragma GCC target("avx2")
#pragma GCC target("popcnt,lzcnt,bmi,bmi2,tune=native")
// #pragma GCC target("avx,fma")
// #pragma GCC target("sse4.2,fma")
// run custom tests with stuff like assert(__builtin_cpu_supports("avx2"))
// or use avx instead of sse4.2, leave fma in as it was covered in avx2
#endif

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

const int N = 2e5 + 7;
int a[N];
array<int, 3> traps[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int m, n, k, t; cin >> m >> n >> k >> t;
    for (int i = 0; i < m; i++) cin >> a[i];
    t -= n + 1;
    int MXD = 0;
    for (int i = 0; i < k; i++) {
        cin >> traps[i][0] >> traps[i][1] >> traps[i][2];
        MXD = max(MXD, traps[i][2]);
    }
    sort(traps, traps + k, [&](auto &t1, auto &t2) -> bool {
        return t1[0] < t2[0];
    });

    auto poss = [&](int lim) -> bool {
        int ans = 0;
        for (int i = 0; i < k;) {
            if (traps[i][2] < lim){
                i++; continue;
            }
            int rLast = traps[i][1], l = traps[i][0];
            int previ = i;
            for (int j = i + 1; j < k; j++) {
                if (traps[j][2] < lim) {
                    if (j == k - 1) {
                        ans += 2 * (rLast - l + 1);
                        if (ans > t) return 0;
                        i = k;
                        break;
                    }
                    continue;
                }
                if (traps[j][0] - 1 <= rLast) {
                    rLast = max(rLast, traps[j][1]);
                    if (j == k - 1) {
                        ans += 2 * (rLast - l + 1);
                        if (ans > t) return 0;
                        i = k;
                        break;
                    }
                } else {
                    ans += 2 * (rLast - l + 1);
                    if (ans > t) return 0;
                    i = j;
                    break;
                }
            }
            if (previ == i) {
                ans += 2 * (rLast - l + 1);
                if (ans > t) return 0;
                break;
            }
        }
        return ans <= t;
    };

    int left = 0, right = MXD + 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (poss(mid)) right = mid;
        else left = mid + 1;
    }
    int cnt = 0;
    for (int i = 0; i < m; i++)  {
        cnt += a[i] >= left - 1;
    }
    cout << cnt << '\n';
    return 0;
}