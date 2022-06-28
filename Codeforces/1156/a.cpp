/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0; bool fail = 0;
    for (int i = 0; i < n - 1; i++) {
        if ((a[i] == 2 && a[i + 1] == 3) || (a[i] == 3 && a[i + 1] == 2)) {
            fail = 1;
            break;
        } else if ((a[i] == 1 && a[i + 1] == 3) || (a[i] == 3 && a[i + 1] == 1)) {
            ans += 4;
        } else ans += 3;
        if (i + 2 < n && a[i] == 3 && a[i + 1] == 1 && a[i + 2] == 2) ans--;
    }
    if (fail) {
        cout << "Infinite\n";
    } else {
        cout << "Finite\n" << ans << '\n';
    }

    return 0;
}