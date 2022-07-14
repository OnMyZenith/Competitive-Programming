/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

const int MX = 1e5 + 7;
bitset<MX> poss;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    poss[0] = 1;
    int n; cin >> n;

    int x;
    while (n--) {
        cin >> x;
        poss |= poss << x;
    }
    cout << poss.count() - 1 << '\n';
    for (int i = 1; i < MX; i++) {
        if (poss[i]) cout << i << ' ';
    }
    cout << '\n';
    return 0;
}
