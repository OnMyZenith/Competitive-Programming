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
    for (int i = 0; i < n; i++) cin >> a[i];

    if(n == 1){ 
        if(a[0] > 1) {
            cout << "NO\n";
            return;
        }else {
            cout << "YES\n";
            return;
        }
    }

    sort(a.begin(), a.end());
    if(a[n - 2] + 1 < a[n - 1]) {
        cout << "NO\n";
        return;
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