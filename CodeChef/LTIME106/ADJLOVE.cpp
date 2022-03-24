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
    vector<int> a(n);
    int co = 0, ce = 0;
    for (auto &u : a) {
        cin >> u;
        co += u & 1;
        ce += !(u & 1);
    }
    if((co < 2) || (co == n && (n & 1))) {
        cout << "-1\n";
        return;
    }
    if(!(co & 1)) {
        for (int i = 0; i < n; i++) {
            if(a[i] & 1) cout << a[i] << " ";
        }
        for (int i = 0; i < n; i++) {
            if(!(a[i] & 1)) cout << a[i] << " ";
        }
        cout << '\n';
    } else {
        bool f = 0; int id = -1;
        for (int i = 0; i < n; i++) {
            if(a[i] & 1) {
                if(!f) {
                    f = 1; id = i; continue;
                }
                cout << a[i] << " ";
            }
        }
        for (int i = 0; i < n; i++) {
            if(!(a[i] & 1)) cout << a[i] << " ";
        }
        cout << a[id];
        cout << '\n';
    }



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