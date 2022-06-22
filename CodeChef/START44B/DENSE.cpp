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
    string s; cin >> s;
    vector<int> preopen(n + 1), suffclose(n + 1);
    for (int i = 0; i < n; i++) preopen[i + 1] = preopen[i] + (s[i] == '(');
    for (int i = n - 1; i >= 0; i--) {
        suffclose[i] = suffclose[i + 1] + (s[i] == ')');
    }
    int best = 0;
    for (int i = 0; i <= n; i++) {
        if (preopen[i] == suffclose[i]) {
            best = preopen[i];
        }
    }
    cout << n - 2 * best << '\n';


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