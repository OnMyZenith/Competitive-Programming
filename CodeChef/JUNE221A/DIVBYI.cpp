/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    a[n - 1] = n;
    vector<bool> taken(n); taken[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        int l = a[i + 1] - (i + 1), r = a[i + 1] + (i + 1);
        if(l < n && l > 0 && !taken[l - 1]) {
            taken[l - 1] = 1;
            a[i] = l;
        } else {
            taken[r - 1] = 1;
            a[i] = r;
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];



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