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
    vector<pair<int,int>> c(3);
    for (auto &[x, y] : c) {
        cin >> x >> y;
    }
    for (int i = 0; i < 3; i++) {
        if(c[i].second == c[(i + 1) % 3].second && c[(i + 2) % 3].second < c[i].second) {
            cout << abs(c[i].first - c[(i + 1) % 3].first) << '\n';
            return;
        }
    }
    cout << "0\n";
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