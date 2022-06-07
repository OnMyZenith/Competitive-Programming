/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    ll cost = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cost += a[i] / k;
        a[i] %= k;
    }
    sort(a.begin(), a.end());
    dbg(cost, a);
    int i = 0, j = n - 1, waste = 0;
    vector<bool> used(n);
    while(i < j) {
        if(a[i] + a[j] < k) waste += a[i++];
        else {
            used[i] = used[j] = 1;
            // waste += (a[i] + a[j]) % k;
            cost++;
            i++, j--;
        }
    }
    dbg(used, i, j);
    cout << cost << '\n';
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