/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


void solve() {
    int n, m, k; cin >> n >> m >> k;
    string a, b, c;
    cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0, k1 = 0, k2 = 0;
    while(i < n && j < m) {
        if (k1 < k && a[i] < b[j]) c += a[i++], k1++, k2 = 0;
        else if (k2 < k && b[j] < a[i]) c += b[j++], k2++, k1 = 0;
        else if (k1 == k) c += b[j++], k2++, k1 = 0;
        else if (k2 == k) c += a[i++], k1++, k2 = 0;
        else assert(false);
    }
    // while (i < n && k1 < k) c += a[i++], k1++, k2 = 0;

    // while (j < m && k2 < k) c += b[j++], k2++, k1 = 0;
    cout << c << '\n';

}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}