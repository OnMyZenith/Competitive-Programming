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
    for (int i = 0; i < n; i++) cin >> b[i];


    int and_a = -1, and_b = -1;

    for (int i = 0; i < n; i++) {
        and_a &= a[i];
        and_b &= b[i];
    }

    for (auto &e : a) {
        e |= and_b;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(a == b) {
        cout << and_b << '\n';
    } else cout << "-1\n";
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