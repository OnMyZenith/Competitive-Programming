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
    int n; string s;
    cin >> n >> s;
    vector<int> res;
    bool p = 1;
    for (int i = n - 2; i >= 0; i--) {
        if(p && s[i] == '1' && s[i + 1] == '0') {
            res.push_back(i + 1); p = 0;
        } else if(!p && s[i] == '0' && s[i + 1] == '1') {
            res.push_back(i + 1); p = 1;
        }
    }
    cout << (int)res.size() << '\n';
    for (auto &u : res) {
        cout << "1 " << u << '\n';
    }
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