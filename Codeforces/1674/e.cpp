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

// Check result >= lo
template <class T, class U> T lt(T lo, T hi, U f) {
    --lo, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo + 1) / 2;
        f(mid) ? lo = mid : hi = mid - 1;
    }
    return lo;
}


int main() {
    vamos;

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int id1 = int(min_element(a.begin(), a.end()) - a.begin()), id2 = -1, mn = 1e9;
    for (int i = 0; i < n; i++) {
        if(mn >= a[i] && i != id1) mn = a[i], id2 = i;
    }
    int ans1 = (a[id1] + 1) / 2 + (a[id2] + 1) / 2;

    int ans2 = 1e9;
    for (int i = 0; i < n - 1; i++) {
        int mx = max(a[i], a[i + 1]); mn = min(a[i + 1], a[i]);
        int x = lt(0, mn, [&](int m){
            return mx - m * 2 >= mn;
        });
        auto ans = [&](int cut) -> int {
            if(cut < 0) cut = 0;
            int _ans = cut;
            mx -= cut * 2; mn -= cut;
            int k = min(mn, mx);
            _ans += (k / 3) * 2;
            int left = abs(mx - mn);
            if(k % 3 == 1) {
                _ans++;
                left--;
            } else if(k % 3 == 2) {
                _ans++;
                left++;
            }
            _ans += (left + 1) / 2;
            return _ans;
        };
        ans2 = min(ans2, ans(x));
    }

    int ans3 = 1e9;
    for (int i = 0; i < n - 2; i++) {
        ans3 = min(ans3, (abs(a[i + 2] - a[i]) + 1) / 2 + min(a[i], a[i + 2]));
    }

    cout << min({ans1, ans2, ans3}) << '\n';

    return 0;
}