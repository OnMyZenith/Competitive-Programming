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
    int odd = 0;
    vector<int> f(100);
    vector<int> b;
    for (int i = 0; i < n; i++) {
        cin >> a[i], odd += a[i] & 1;
        a[i] %= 100;
        if(f[a[i]] < 3) {
            b.push_back(a[i]);
            f[a[i]]++;
        }
    }
    n = (int)b.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if((b[i] + b[j] + b[k]) % 10 == 3) {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    cout << "NO\n";
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