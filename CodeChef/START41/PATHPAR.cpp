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
    ll n, k; cin >> n >> k;
    if(n == 1) {
        if((n & 1) == k) {
            cout << "Yes\n";
            return;
        } else {
            cout << "No\n";
            return;
        }
    }
    if(n % 2 == 0) {
        cout << "Yes\n";
        return;
    }
    if(k) {
        cout << "Yes\n";
    } else {

        cout << "No\n";
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