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


vector<long long> trial_division3(long long n) {
    vector<long long> factorization;
    for (int d : {2, 3, 5}) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7; d * d <= n; d += increments[i++]) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}


template <class T> T powf(T a, long long b) { T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r; }


void solve() {
    ll x; int c; cin >> x >> c;
    auto f = trial_division3(x);
    unordered_map<ll, int> m;
    for (auto &u : f) {
        m[u]++;
    }
    ll y = 1;
    dbg(f);
    for (auto &[fac, freq] : m) {
        y *= powf(fac, min(c - freq % c, freq % c));
    }
    cout << y << '\n';
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