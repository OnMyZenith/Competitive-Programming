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




void solve(int _TC) {
    vector<vector<int>> a(3, vector<int>(4));
    for (auto &p : a) { // 3 printers
        for (auto &c : p) { // 4 colours
            cin >> c;
        }
    }
    vector<int> res(4, 1e6);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            res[i] = min(res[i], a[j][i]);
        }
    }
    if(accumulate(res.begin(), res.end(), 0) < 1e6) {
        cout << "Case #" << _TC << ": IMPOSSIBLE\n";
        return;
    }
    int d = 1e6;
    for (int i = 0; i < 4; i++) {
        if(res[i] > d) res[i] = d, d = 0;
        else d -= res[i];
    }

    cout << "Case #" << _TC << ": ";
    for (int i = 0; i < 4; i++) cout << res[i] << " \n"[i == 3];
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    for (int TC = 1; TC <= TT; TC++) {
        solve(TC);
    }

    return 0;
}