/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    cout << "? 0";
    for (int i = 1; i < 100; i++) {
        cout << " " << i;
    }
    cout << endl;
    int x1; cin >> x1;

    cout << "? " << (1 << 7);
    for (int i = 2; i <= 100; i++) {
        cout << " " << (i << 7);
    }
    cout << endl;
    int x2; cin >> x2;

    for (int i = 0; i < 100; i++) {
        for (int j = 1; j <= 100; j++) {
            if ((i ^ (j << 7)) == (x1 ^ x2)) {
                cout << "! " << (x1 ^ i) << endl;
                // return 0;
            }
        }
    }

    return 0;
}