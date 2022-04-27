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



void solve(int _TC) {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int i = 0, j = n - 1;
    int mx = 0, ans = 0;
    while(j < n && i <= j) {
        dbg(i, j);
        if(a[i] <= a[j]) {
            if(mx <= a[i]) {
                ckmax(mx, a[i]);
                i++; ans++; 
            } else i++;
        } else {
            if(mx <= a[j]) {
                ckmax(mx, a[j]);
                j--; ans++; 
            } else j--;
        }
    }
    cout << "Case #" << _TC << ": ";
    cout << ans << '\n';
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    for (int TC = 1; TC <= TT; TC++) {
        solve(TC);
    }

    return 0;
}