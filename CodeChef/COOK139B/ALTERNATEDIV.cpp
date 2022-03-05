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
    vector<int> a(2 * n);
    iota(a.begin(), a.end(), 1);
    set<int> s(a.begin(), a.end());

    for (int i = 0; i < n / 2; i++) {
        int x = *s.begin();
        s.erase(x), s.erase(2 * x);
        cout << x << " " << 2 * x << " ";
    }
    if(n & 1) {
        cout << *s.begin() << '\n';
    } else cout << '\n';
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