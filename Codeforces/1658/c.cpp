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
    for (auto &u : a) {
        cin >> u;
    }
    if(n == 1 && a[0] == 1) {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if(a[(i + 1) % n] - a[i] > 1) {
            cout << "NO\n";
            return;
        }
    }
    int mx_idx = int(max_element(a.begin(), a.end()) - a.begin());

    int one_idx = int(find(a.begin(), a.end(), 1) - a.begin());
    if(one_idx == n || a[(one_idx + 1) % n] != 2 || count(a.begin(), a.end(), 1) > 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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