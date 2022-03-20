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
    int n = (int)s.size();
    int sm = 0;
    for (char c : s) sm += c - '0';

    int r = sm % 9;
    vector<int> poss;
    for (int i = 0; i < 10; i++) {
        if((i - (9 - r)) % 9 == 0) poss.push_back(i);
    }
    

    auto result = [&](char ch) -> string {
        string res; bool f = 0;
        for (char c : s) {
            if(!f && c > ch) res += ch, f = 1;
            res += c;
        }
        if(!f) res += ch;
        return res;
    };
    string fin = result(poss[0] + '0');
    if(fin[0] == '0') {
        fin = s[0];
        fin += '0';
        if(n > 1) fin += s.substr(1);
    }
    cout << "Case #" << _TC << ": ";
    cout << fin << '\n';
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