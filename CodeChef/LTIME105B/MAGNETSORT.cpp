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
    int n; cin >> n;
    vector<int> a(n), b;
    for (auto &u : a) {
        cin >> u;
    }
    b = a;
    sort(a.begin(), a.end());
    string polar; cin >> polar;
    int left = 0, right = n - 1;
    for (int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            left = i; break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if(a[i] != b[i]) {
            right = i; break;
        }
    }
    if(a != b && (!count(polar.begin(), polar.end(), 'N') || !count(polar.begin(), polar.end(), 'S'))) {
        cout << "-1\n"; return;
    }
    if(a == b) {
        cout << "0\n"; return;
    }
    if((count(polar.begin(), polar.begin() + left + 1, 'N')) && (count(polar.begin() + right, polar.end(), 'S'))) {
        cout << "1\n"; return;
    }
    if((count(polar.begin(), polar.begin() + left + 1, 'S')) && (count(polar.begin() + right, polar.end(), 'N'))) {
        cout << "1\n"; return;
    }
    cout << "2\n";

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