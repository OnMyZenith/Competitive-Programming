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

int n, sum;
vector<int> a;

void solve() {
    bitset<200000> dp;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        dp |= dp << a[i];
    }
    if(!dp[sum / 2]) {
        cout << "0\n";
        return;
    } else {
        for (int skip = 0; skip < n; skip++) {
            dp.reset(); dp[0] = 1;
            for (int i = 0; i < n; i++) {
                if(i != skip) dp |= dp << a[i];
            }
            int s1 = sum - a[skip];
            if((s1 & 1) || !dp[s1 / 2]) {
                cout << "1\n";
                cout << skip + 1 << '\n';
                return;
            }
        }
    }
}

// void solve() {
//     int odd = -1;
//     for (int i = 0; i < n; i++) {
//         if(a[i] & 1) odd = i;
//     }
//     if(odd != -1) {
//         cout << "1\n" << odd + 1 << '\n';
//         return;
//     } else {
//         for (auto &u : a) {
//             u /= 2;
//         }
//         solve();
//     }
// }

int main() {
    vamos;

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sum = accumulate(a.begin(), a.end(), 0);
    if(sum & 1) {
        cout << "0\n";
    } else solve();

    return 0;
}