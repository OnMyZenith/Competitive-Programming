/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    reverse(a.begin(), a.end());

    string res;
    int cnt1 = 0, i = 0;
    for (; i < n && a[i] == 1; i++, cnt1++, res += '1') ;
    // dbg(cnt1);

    int curr = !!(cnt1), tot = 0;
    for (; i < n; i++) {
        if (a[i] > curr && curr < q) curr++, tot++, res += '1';
        else if (a[i] <= curr) tot++, res += '1';
        else res += '0';
    }
    reverse(res.begin(), res.end());
    cout << res << '\n';


}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}
