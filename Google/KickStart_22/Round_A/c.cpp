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
    int n; cin >> n;
    string s; cin >> s;
    int m = (int)count(s.begin(), s.end(), '?');

    // auto isPal = [&](string ns) -> bool {
    //     string p = ns;
    //     reverse(p.begin(), p.end());
    //     return ns == p;
    // };

    // auto fine = [&](string p) -> bool {
    //     for (int i = 0; i < n - 4; i++) {
    //         if(isPal(p.substr(i, 5))) return false;
    //     }
    //     for (int i = 0; i < n - 5; i++) {
    //         if(isPal(p.substr(i, 6))) return false;
    //     }
    //     return true;
    // };
    // bool poss = 0;
    // for (int i = 0; i < (1 << m); i++) {
    //     string res;
    //     for (int j = 0, cnt = 0; j < n; j++) {
    //         if(s[j] != '?') res += s[j];
    //         else {
    //             res += ((i >> cnt++) & 1) ? '0' : '1'; 
    //         }
    //     }
    //     dbg(res);
    //     if(fine(res)) {
    //         poss = 1; break;
    //     }
    // }

    // for (int i = 0; i < (1 << 6); i++) {
    //     string res;
    //     for (int j = 0; j < 6; j++) {
    //         res += ((i >> j) & 1) ? '0' : '1'; 
    //     }
    //     if(!isPal(res)) dbg(res);
    // }


    // for (int i = 0; i < (1 << 5); i++) {
    //     string res;
    //     for (int j = 0; j < 5; j++) {
    //         res += ((i >> j) & 1) ? '0' : '1';
    //     }
    //     if(!isPal(res)) dbg(res);
    // }

    bool poss = 1;
    for (int i = 0; i < n - 3; i++) {
        poss &= !(s[i] == s[i + 1] && s[i + 2] == s[i + 1] && s[i + 2] == s[i + 3]);
    }



    cout << "Case #" << _TC << ": ";
    cout << (poss ? "POSSIBLE" : "IMPOSSIBLE") << '\n';
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