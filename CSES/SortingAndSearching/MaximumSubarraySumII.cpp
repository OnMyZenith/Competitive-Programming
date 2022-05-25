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
    int n, lo, hi; cin >> n >> lo >> hi;
    vector<int> a(n);
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i + 1] = a[i] + pre[i];
    }
    multiset<ll> q;
    ll best = pre[lo];
    dbg(pre);
    for (int i = lo - 1; i < n; i++)  {
        q.insert(pre[i - lo + 1]);
        if (i >= hi) {
            auto it = q.find(pre[i - hi]);
            assert(it != q.end());
            q.erase(it);
        }
        dbg(q);
        best = max(best, pre[i + 1] - *q.begin());
    }
    cout << best << '\n';
}

int main() {
    vamos;

    int TT = 1;
    // cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}
