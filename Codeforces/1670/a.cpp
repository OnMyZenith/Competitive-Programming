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
    int neg = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] < 0) neg++;
    }
    for (int i = 0; i < n; i++, neg--) {
        if(neg > 0 && a[i] > 0) a[i] = -a[i];
        if(neg <= 0 && a[i] < 0) a[i] = -a[i];
    }
    cout << (is_sorted(a.begin(), a.end()) ? "YES" : "NO") << '\n';
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