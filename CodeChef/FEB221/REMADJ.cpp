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

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }

void solve() {
    int n; cin >> n; vector<int> a(n); vector<ll> pre(n+1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i + 1] = pre[i] + a[i];
    }
    int best = n - 1;
    if(!pre[n]){
        int res = 0;
        for (int i = 0, new_i = 1; new_i <= n; i = new_i++) {
            while(new_i <= n && pre[new_i]) new_i++;
            // res += new_i - i - 1;
            if (new_i <= n) {res += new_i - i - 1;}
        }
        ckmin(best, res);
        cout << best << '\n';
        return;
    }

    for (int cnt = 1; cnt <= n; cnt++) { // cnt of items in prefix that are combined
        if(!pre[cnt] || (pre[n] % pre[cnt])) continue;

        int res = 0;
        for (int l = 0, r = 1; r <= n; l = r++) {
            if(pre[n] - pre[l] == pre[cnt]){ res += n - l - 1; break;}
            while (r <= n && pre[r] != pre[cnt] + pre[l]) r++;
            if (r <= n) {res += r - l - 1;}
            else {
                res = n; break;
            }
        }
        ckmin(best, res);
    }
    cout << best << '\n';
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    for (int TC = 1; TC <= TT; TC++) {
        solve();
    }

    return 0;
}