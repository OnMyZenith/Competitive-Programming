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

char solve(char c, ll t, ll k) {
    if(!t) {
        assert(k == 1);
        return c;
    }
    switch (c) {
    case 'A':
        if(k > (1LL << (t - 1))) {
            return solve('C', t - 1, k - (1LL << (t - 1)));
        }
        return solve('B', t - 1, k);
    case 'B':
        if(k > (1LL << (t - 1))) {
            return solve('A', t - 1, k - (1LL << (t - 1)));
        }
        return solve('C', t - 1, k);
    default:
        if(k > (1LL << (t - 1))) {
            return solve('B', t - 1, k - (1LL << (t - 1)));
        }
        return solve('A', t - 1, k);
    }
}

int main() {
    vamos;
    string s; int q;
    cin >> s >> q;
    int n = (int)s.size();
    while(q--) {
        ll t, k; cin >> t >> k;
        for (int i = 0; i < n; i++) {
            if(k <= (1LL << t)) {
                cout << solve(s[i], t, k) << '\n';
                break;
            }
            k -= (1LL << t);
        }
    }

    return 0;
}