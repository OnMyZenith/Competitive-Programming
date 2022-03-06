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
    vector<int> v(n);
    for (auto &u : v) {
        cin >> u;
    }
    int i = 0, j = n - 1;
    while(i < n && v[i] ) i++;
    while(j >=0 && v[j]) j--;
    // j = max(j, 0);
    // i = min(n- 1, i);
    cout << max(0, j - i + 2) << '\n';



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