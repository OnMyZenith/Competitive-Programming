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
    int r, c; cin >> r >> c;
    string plus = "+", pipe = "|";
    for (int i = 0; i < c; i++) {
        plus += "-+";
        pipe += ".|";
    }
    cout << "Case #" << _TC << ":\n";

    cout << ".." + plus.substr(2) << '\n';
    cout << ".." + pipe.substr(2) << '\n';
    cout << plus << '\n';
    for (int i = 0; i < r - 1; i++) {
        cout << pipe << '\n';
        cout << plus << '\n';
    }
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