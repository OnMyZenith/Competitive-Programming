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


// Check result against SIZE of vector
template <class T> int upbf(vector<T> &a, const T &b) { return int(upper_bound(a.begin(), a.end(), b) - begin(a)); }


void solve() {
    string s; cin >> s;
    int n = (int)s.size();
    vector<vector<int>> f(26);
    for (int i = 0; i < n; i++) {
        f[s[i] - 'a'].push_back(i);
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++) if((int)f[i].size()) cnt++;
    bool poss = 1;
    if(cnt > 1) for (int i = 0; i < n - 1; i++) poss &= s[i] != s[i + 1];
    for (int i = 0, j = cnt; j < n; i += cnt, j += cnt) {
        for (int k = 0; k < cnt && j + k < n; k++) {
            poss &= s[i + k] == s[j + k];
        }
        // int len = min(cnt, n - cnt);
        // dbg(len);
        // if(len) {
        //     poss &= s.substr(i, len) == s.substr(i + cnt, len);
        // }
    }

    // for (int i = 0; i < n; i++) {
    //     int nxt = upbf(f[i], i);
    //     int idx = (nxt != (int)f[i].size() ? f[i][nxt] : n);
    //     poss &= (idx == n) || ((idx - i) == cnt);
    // }
    cout << (poss ? "YES" : "NO") << '\n';




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