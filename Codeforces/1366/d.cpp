/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

const int MAX_PR = 10'000'000;
bitset<MAX_PR> isprime;

int oneFac[int(1e7) + 1];

void eratosthenesSieve(int lim) {

    isprime.set();
    isprime[0] = isprime[1] = 0;

    for (int i = 4; i < lim; i += 2)
        isprime[i] = 0, oneFac[i] = 2;

    for (int i = 3; i * i < lim; i += 2)
        if (isprime[i])
            for (int j = i * i; j < lim; j += i * 2)
                isprime[j] = 0, oneFac[j] = i;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    eratosthenesSieve(1e7 + 1);

    int n; cin >> n;
    vector<array<int, 2>> ans(n, {-1, -1});
    for (int j = 0, x; j < n; j++) {
        cin >> x;
        if(oneFac[x]) {
            int y = x / oneFac[x];
            while (y % oneFac[x] == 0) y /= oneFac[x];
            if(y > 1) {
                ans[j] = {oneFac[x], y};
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i][0] << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i][1] << " \n"[i == n - 1];
    }

    return 0;
}