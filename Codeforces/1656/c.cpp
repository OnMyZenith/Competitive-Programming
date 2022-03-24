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


template <class T> void remDupf(vector<T> &v) { sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), end(v)); }


void solve() {
    int n; cin >> n;
    vector<int> a; a.reserve(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if(!x) continue;
        a.push_back(x);
    }
    n = (int)a.size();
    sort(a.begin(), a.end());
    if(n < 1) {
        cout << "YES\n";
        return;
    }
    int aa = a[0]; bool eq = 1;
    for (int i = 0; i < n; i++) {
        eq &= a[i] == aa;
    }
    if(eq) {
        cout << "YES\n";
        return;
    }
    if(n == 1) {
        cout << "NO\n";
        return;
    }
    if(a[0] == 1) {
        cout << "NO\n";
        return;
    }
    // int j = 0;
    // while(j < n - 1){
    //     int d = a[j], g = 0;
    //     for (int i = j; i < n; i++) {
    //         a[i] -= d;
    //         g = gcd(a[i], g);
    //     }
    //     if(g > 1 || g == 0) {
    //         cout << "YES\n";
    //         return;
    //     }
    //     j++;
    // }
    cout << "YES\n";
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