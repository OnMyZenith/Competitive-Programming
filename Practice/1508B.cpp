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
    int n; ll k; cin >> n >> k;

    ll sum = 0, curr = 1;
    for (int i = 1; i <= n; i++) {
        sum += curr;
        if(sum > k){
            sum -= curr;
            break; 
        }
        curr *= 2;
    }
    if(curr > n) {
        cout << "-1\n";
        return;
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