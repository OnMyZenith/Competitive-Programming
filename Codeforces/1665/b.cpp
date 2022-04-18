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
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }



void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &u : a) {
        cin >> u;
    }
    sort(a.begin(), a.end());
    int best = 1, curr = 1;
    for (int i = 0; i < n - 1; i++) {
        if(a[i] == a[i + 1]) {
            curr++;
            ckmax(best, curr);
        } else curr = 1;
    }
    int ans = 0;
    int score = best, usable = score;
    while(score < n) {
        ans++;
        while(score < n && usable > 0) {
            // dbg(score, usable, ans);
            score ++;
            usable--;
            ans++;
        }
        // if(usable == 1 && score == n - 1) {
        //     ans++;
        //     break;
        // }
        // dbg(score, usable, ans);
        usable += score;
    }
    cout << ans << '\n';
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