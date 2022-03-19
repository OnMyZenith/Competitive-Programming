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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto &u : a) {
        cin >> u;
    }
    sort(a.begin(), a.end());
    int s = 0, c = 0;
    for (int i = 0; i < n; i++) {
        if(s + a[i] <= k) {
            s += a[i]; c++;
        } else if(s + (a[i] + 1) / 2 <= k) {
            c++; break;
        }
    }
    cout << c << '\n';



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