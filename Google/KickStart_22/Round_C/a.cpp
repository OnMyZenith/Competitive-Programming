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
    int n; string s; cin >> n >> s;

    bool a = 0, A = 0, spl = 0, num = 0;
    for (auto &c : s) {
        num |= c >= '0' && c <= '9';
        a |= c >= 'a' && c <= 'z';
        A |= c >= 'A' && c <= 'Z';
        spl |= c == '&' || c == '@' || c == '#' || c == '*';
    }
    if(!spl) s += '@';
    if(!a) s += 'a'; 
    if(!num) s += '1'; 

    if(!A) s += 'A';
    while(s.length() < 7) s += 'a';




    cout << "Case #" << _TC << ": ";
    cout << s << '\n';

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