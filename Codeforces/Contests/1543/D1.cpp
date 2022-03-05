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
    int n, k; cin >> n >> k;
    int curr = 0;

    auto q = [&] (int g) ->bool{
        cout << (curr ^ g) << endl;
        curr ^= g ^ curr;
        int x; cin >> x;
        if(x == -1) exit(0);
        else return x;
    };

    for (int guess = 0; guess < n; guess++) {
        if(q(guess)) return;
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