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
    string s;
    cin >> s;
    map<char, bool> mp;
    int d = 'a' - 'A';
    for (int i = 0; i < 6; i++) {
        if(s[i] > 'Z') mp[s[i]] = 1;
        else {
            if(!mp[s[i] + d]) {
                cout << "NO\n";
                return;
            }
        }
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