/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

// 0.6s for 1e8 (GNU G++17 (64 bit 9.2.0, mysys 2))
const int MAX_PR = 100'000'000;
bitset<MAX_PR> isprime;
vector<int> primes;
vector<int> eratosthenesSieve(int lim) {

    isprime.set();
    isprime[0] = isprime[1] = 0;

    for (int i = 4; i < lim; i += 2)
        isprime[i] = 0;

    for (int i = 3; i * i < lim; i += 2)
        if (isprime[i])
            for (int j = i * i; j < lim; j += i * 2)
                isprime[j] = 0;

    vector<int> pr;
    for (int i = 2; i < lim; i++)
        if (isprime[i]) pr.push_back(i);

    return pr;
}

void solve() {
    int a, b; cin >> a >> b;
    vector<array<int, 2>> factors_a;
    a = max(a, b) - min(a, b);
    for (auto &p : primes) {
        if (a == 1) break;
        while (a % p == 0) {
            a /= p;
            if(factors_a.empty() || factors_a.back()[0] != p) factors_a.push_back({p, 1});
            else factors_a.back()[1]++;
        }
    }
    dbg(factors_a);
    ll ans = 1;
    for (auto &[f, fr] : factors_a) {
        ans *= ll(fr + 1);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;
    primes = eratosthenesSieve(1e5 + 7);
    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}