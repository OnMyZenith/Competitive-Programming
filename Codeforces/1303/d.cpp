/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
const int MX = 10;
#else
#define dbg(...) 007
const int MX = 64;
#endif

constexpr int log_2(ll x) { return x > 0 ? (8 * (int)sizeof(x)) - 1 - __builtin_clzll(x) : -1; } // Floor of log_2(x); index of highest 1-bit

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(m);
    vector<int> f(MX), req(MX);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        f[log_2(a[i])]++;
    }
    dbg(f);
    dbg(bitset<10>(n));
    int ans = 0;
    for (int i = 0; i < MX; i++) {
        if (1 & (n >> i)) {
            if (f[i]) {
                f[i]--;
                if (f[i] >= 2) {
                    f[i + 1] += f[i] / 2;
                }
            } else {
                dbg(i);
                for (int j = i + 1; j < MX; j++) {
                    if (f[j]) {
                        for (int k = j; k >= i + 1; k--) {
                            f[k]--;
                            ans++;
                            f[k - 1] += 2;
                        }
                        break;
                    }
                }
                if (!f[i]) {
                    cout << "-1\n";
                    return;
                }
                f[i]--;
            }
        } else if (f[i] >= 2) {
            f[i + 1] += f[i] / 2;
        }
        
        // req[i] = (n >> i) & 1ll;
        // if (req[i] && f[i] > 2) {
        //     f[i + 1] += ((f[i] - 1) / 2);
        //     f[i] -= ((f[i] - 1) / 2) * 2;
        // } else if (!req[i] && f[i] == 2) {
        //     f[i + 1]++;
        //     f[i] = 0;
        // }
    }

    cout << ans << '\n';




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