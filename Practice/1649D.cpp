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

// Check result against SIZE of vector
template <class T> int lwbf(vector<T> &a, const T &b) { return int(lower_bound(a.begin(), a.end(), b) - begin(a)); }
template <class T> void remDupf(vector<T> &v) { sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), end(v)); }


void solve() {
    int n, c; cin >> n >> c;
    vector<int> a(n), b;
    vector<bool> pres(c + 1);
    for (auto &u : a) {
        cin >> u; pres[u] = 1;
    }
    remDupf(a);
    for (int i = 1; i <= c; i++) {
        if(!pres[i]) b.push_back(i);
    }
    int m = (int)b.size();
    n = (int)a.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ll x = (ll) b[j] * a[i];
            if(x > c) break;
            int idx = lwbf(a, (int)x);
            if(idx != n && a[idx] < x + a[i]) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
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