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


void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        a[i] = b[i] - a[i];
    }
    dbg(a);
    bool found_zero = 0;
    for (int i = 0; i < n; i++) {
        if(a[i] < 0) {
            cout << -1 << '\n';
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        if(!a[i]) {
            found_zero = 1;
            for (int j = i; j < n; j++, i++) {
                if(a[j]) {
                    for (int k = j; k < n; k++, j++, i++) {
                        if(!a[k]) {
                            cout << -1 << '\n';
                            return;
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    if(found_zero) {
        int curr = a[0];
        for (int i = 0; i < n; i++) {
            if(!a[i]){
                break;
            }
            if(curr < a[i]) {
                cout << -1 << '\n';
                return;
            } else curr = a[i];
        }
        curr = a[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            if(!a[i]){
                break;
            }
            if(curr < a[i]) {
                cout << -1 << '\n';
                return;
            } else curr = a[i];
        }
        ans = a[0] + a[n - 1];
    } else {
        bool down = 0, up = 0;
        int m1 = -1, m2 = -1, p = -1, peaks = 0, lows = 0;
        for (int i = 0; i < n - 1; i++) {
            if(a[i] < a[i + 1]) {
                up = 1;
                if(down) {
                    if(m1 == -1) m1 = i;
                    else m2 = i;
                    down = 0;
                    lows++;
                }
            }
            if(a[i] > a[i + 1]) {
                down = 1;
                if(up) {
                    if(p == -1) p = i;
                    // if(m1 == -1) m1 = 0, lows++;
                    up = 0;
                    peaks++;
                }
            }
        }
        if(peaks > 1 || lows > 2) {
            cout << -1 << '\n';
            return;
        }
        if(m1 != -1 && p != -1 && m2 == -1) m2 = n - 1;
        if(p != -1 && m1 == -1) {m1 = 0, m2 = n - 1;}
        if(p == -1 && m1 == -1) {
            ans = max(a[0], a[n - 1]);
        } else if(p == -1 && m1 != -1) {
            ans = a[0] + a[n - 1] - a[m1];
        }  else {
            if(a[p] > a[m1] + a[m2]) {
                cout << -1 << '\n';
                return;
            }
            int cnt = a[m1] + a[m2] - a[p];
            ans = a[0] + a[n - 1] - cnt;
        }
        dbg(peaks, lows);
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