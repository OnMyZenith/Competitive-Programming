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


// Check result <= hi
template <class T, class U> T ft(T lo, T hi, U f) {
    ++hi, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo) / 2;
        f(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}


void solve() {
    int n; cin >> n;
    vector<vector<int>> children(n);

    for (int i = 1; i < n; i++) {
        int p; cin >> p; p--;
        children[p].push_back(i);
    }
    vector<int> fin = {1};
    for (int i = 0; i < n; i++) {
        if((int)children[i].size()) fin.push_back((int)children[i].size());
    }
    sort(fin.rbegin(), fin.rend());
    int m = (int)fin.size();
    vector<int> inf_time(m); iota(inf_time.begin(), inf_time.end(), 1);

    int ex = ft(0, n, [&](int x) -> bool {
        int left = 0;
        for (int i = 0; i < m; i++) {
            left += max(fin[i] - 1 - (m + x - inf_time[i]), 0);
        }
        return left <= x;
    });
    cout << ex + m << '\n';
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