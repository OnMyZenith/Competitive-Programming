/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


template <class T> T powfun(T a, long long b) { T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r; }

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll MX = *max_element(a.begin(), a.end());
    int cnt = 0; ll x = 1;;
    while(x <= MX) x *= k, cnt++;
    vector<ll> powk(cnt + 1);
    vector<ll> res(cnt + 1);

    for (int i = 0; i < n; i++) {
        for (int j = cnt; j >= 0; j--) {
            if(powfun(k, j) <= a[i]) {
                a[i] -= powfun(k, j);
                res[j]++;
            }
        }
    }
    if(*max_element(res.begin(), res.end()) > 1 || *max_element(a.begin(), a.end()) > 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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