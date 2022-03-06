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
    vector<int> whats_at(n), pos_of(n);
    for (int i = 0; i < n; i++) {
        cin >> whats_at[i]; whats_at[i]--;
        pos_of[whats_at[i]] = i;
    }
    int cnt = 1, border = 0;
    vector<bool> vis(n);
    dbg(whats_at, pos_of);
    for (int i = 0; i < n; i++) {
        if(i > border) cnt++;
        int x = whats_at[i];
        if(vis[x]) continue; else vis[x] = 1;
        while(x-- >= 1){
            if(vis[x]) break; else vis[x] = 1;
            dbg(border);
            ckmax(border, pos_of[x]);
            dbg(border);
        }
    }
    cout << cnt << '\n';
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