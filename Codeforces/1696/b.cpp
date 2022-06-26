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
    vector<int> a(n), res;
    for (int i = 0; i < n; i++) cin >> a[i];


    for (int i = 0, cnt = 0; i < n; i++) {
        if (a[i] == 0) {
            if (cnt) res.push_back(cnt), cnt = 0;
        } else cnt++;
        if (i == n - 1 && cnt) res.push_back(cnt);
    }
    cout << min((int)res.size(), 2) << '\n';



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