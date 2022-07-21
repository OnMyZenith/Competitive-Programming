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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> zeros;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') zeros.push_back(i);
    }
    int best = 0, lstZero = -1;
    for (int i = 0; i < n; i++) {
        int ex = i - lstZero - 1;
        int j = int(lower_bound(zeros.begin(), zeros.end(), i + k) - zeros.begin());
        if (j == (int)zeros.size()) best = max(best, n - i + ex);
        else best = max(best, zeros[j] - i + ex);
        if (s[i] == '0') lstZero = i;
    }
    cout << best << '\n';
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
