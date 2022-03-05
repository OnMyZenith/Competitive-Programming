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
    int n; string a, b; cin >> n >> a >> b;
    vector<int> ca(n), cb(n);
    for (int i = 0; i < n; i++) {
        ca[i] = (i ? ca[i - 1] : 0) + (a[i] == '1');
        cb[i] = (i ? cb[i - 1] : 0) + (b[i] == '1');
    }
    vector<bool> legit(n);
    for (int i = 0; i < n; i++) if(ca[i] * 2 == i + 1) legit[i] = 1;
    for (int i = n - 1; i >= 0;) {
        if(a[i] == b[i]){i--; continue;}

        if(!legit[i]) {
            cout << "NO\n";
            return;
        } else {
            while(i >= 0 && a[i] != b[i]) {
                i--;
            }
            if(i >= 0 && a[i] == b[i]) {
                if(!legit[i]) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
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