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
    int n; string t; cin >> n >> t;
    for (int i = 0; i < n; i++) {
        s[i] = t[i] == '1';
    }
    int c00 = 0, cp = 0, odd = 0;
    for (int i = 0, j = n - 1; i <= j; i++, j--) {
        if(i == j) {
            if(!s[i]) odd = 1;
            break;
        }
        if(s[i] ^ s[j]) cp++;
        else if(!s[i]) c00++;
    }

    int bob = 0, alice = odd;

    if (cp) {
        if (c00) {
            bob += cp - 1 + 2;
            alice = 1;
        } else {
            bob += cp;
        }
    } else {
        if (odd) {
            if (c00) bob += 2;
        } else if (c00) alice += 2;
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