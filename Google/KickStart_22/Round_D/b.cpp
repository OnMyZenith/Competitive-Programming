/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


void solve(int _TC) {
    int n, m, k; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (auto &e : b) {
        cin >> e;
    }
    cin >> k;

    auto calc = [&](const vector<int> &c, int K) -> ll {
        K = min(K, (int)c.size());
        ll curr_points = 0;
        ll max_points = 0;
    
        for (int i = 0; i < K; i++)
            curr_points += c[i];
    
        max_points = curr_points;
    
        int j = (int)c.size() - 1;
        for (int i = K - 1; i >= 0; i--) {
            curr_points = curr_points + c[j] - c[i];
            max_points = max(curr_points, max_points);
            j--;
        }
        return max_points;
    };



    ll ans = 0;
    for (int i = 0; i <= k; i++) {
        ans = max(ans, calc(a, i) + calc(b, k - i));
    }





    cout << "Case #" << _TC << ": ";
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    for (int TC = 1; TC <= TT; TC++) {
        solve(TC);
    }

    return 0;
}