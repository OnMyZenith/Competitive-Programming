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

int main() {
    vamos;

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto poss = [&](ll lim) -> bool {
        ll curr = 0; int used = 1;
        for (int i = 0; i < n; i++) {
            if(curr + a[i] <= lim) curr += a[i];
            else curr = a[i], used++;
        }
        return used <= k;
    };

    ll lo = *max_element(a.begin(), a.end()), hi = accumulate(a.begin(), a.end(), 0ll);
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if(poss(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << '\n';

    return 0;
}