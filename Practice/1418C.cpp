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

int n;
bitset<200007> a;
vector<vector<bool>> done;
vector<vector<int>> dp;

int go(int i, bool me) {
    if(i >= n) return 0;
    if(done[i][me]) return dp[i][me];
    if(me){
        dp[i][1] = min(go(i + 1, !me), go(i + 2, !me));
    } else {
        dp[i][0] = min(go(i + 1, !me) + a[i], go(i + 2, !me) + a[i] + a[i + 1]);
    }
    done[i][me] = 1;
    return dp[i][me];
}

void solve() {
    cin >> n;
    dp.resize(n, vector<int>(2));
    done.resize(n, vector<bool>(2));
    for (int i = 0; i < n; i++) {
        int x; cin >> x; a[i] = x; done[i][1] = done[i][0] = 0;
    }
    go(0, 0);
    cout << dp[0][0] << '\n';
    // bool me = 0;
    // int ans = 0;
    // for (int i = 0; i < n; i++, me = !me) {
    //     if(i == n - 1) {ans += !me && a[i]; break;}
    //     if(me) {
    //         if(a[i + 1] == 1) i++;
    //     } else {
    //         ans += a[i];
    //         if(!a[i + 1]) i++;
    //     }
    // }
    // cout << ans << '\n';
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