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
    int n, m, k; cin >> n >> m >> k;
    auto poss = [&](int N, int M, int K) -> bool {
        if(N & 1) return (K >= M / 2) && (!(((M / 2) - K) & 1));
        return ((M <= K) && (!((M - K) & 1))) || (!(K & 1));
    };
    cout << (poss(n, m, k) && poss(m, n, n * m / 2 - k) ? "YES" : "NO") << '\n';
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