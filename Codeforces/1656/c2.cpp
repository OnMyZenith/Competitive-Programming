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
    vector<int> a(n);
    for (auto &u : a) {
        cin >> u;
    }
    remDupf(a);
    reverse(a.begin(), a.end());
    if(a.back() == 0) a.pop_back();
    reverse(a.begin(), a.end());
    n = (int)a.size();
    if(n <= 1) {
        cout << "YES\n";
        return;
    }
    sort(a.begin(), a.end());
    bool allOdd = 1, allEven = 1;
    for (int i = 0; i < n; i++) {
        allOdd &= (a[i] & 1);
        allEven &= !(a[i] & 1);
    }
    if((allOdd && a[0] != 1) || allEven) {
        cout << "YES\n";
        return;
    }
    int d = a[1] - a[0];
    if(!d) {
        cout << "YES\n";
        return;
    }
    cout << ((d > 1 && (a[1] % d != 1)) ? "YES" : "NO") << '\n';
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