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
    string s; cin >> s;
    string r;
    int n = (int)s.size();
    for (int i = 0; i < n - 1; i++) {
        // if(s[i] < s[i + 1]) r += s[i], r += s[i];
        // else if (s[i] == s[i + 1]) {
            int e = i + 1;
            while(e < n && s[i] == s[e]) e++;
            if(e < n) {
                if(s[e] > s[i]) {
                    r += s.substr(i, e - i);
                    r += s.substr(i, e - i);
                    i = e - 1;
                } else {
                    r += s.substr(i, e - i);
                    i = e - 1;
                }
            } else {
                r += s.substr(i);
                break;
            }
        // }
        // else r += s[i];
        if(i == n - 2) r += s.back();
    }
    // r += s.back();


    if(n == 1) r = s;


    cout << "Case #" << _TC << ": " << r  << '\n';

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