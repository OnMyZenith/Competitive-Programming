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


bitset<1007> s;

void solve() {
    int n; string t; cin >> n >> t; s.reset();
    for (int i = 0; i < n; i++) {
        if(t[i] == '1') s[i] = 1;
    }
    int c0 = 0, cp = 0, odd = 0;
    for (int i = 0, j = n - 1; i <= j; i++, j--) {
        if(i == j) {
            if(!s[i]) odd = 1;
            break;
        }
        if(s[i] ^ s[j]) cp++;
        else if(!s[i]) c0 += 2;
    }

    int bob = cp, alice = 0;
    if(odd) {
        alice++;
        bool a = 0;
        while(c0) {
            if(a) alice += 2;
            else bob += 2;
            c0 -=2;
            a = !a;
        }
    } else {
        bool a = 1;
        while(c0) {
            if(a) alice += 2;
            else bob += 2;
            c0 -=2;
            a = !a;
        }
    }

    if(alice > bob) cout << "BOB\n";
    else if(alice < bob) cout << "ALICE\n";
    else cout << "DRAW\n";
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