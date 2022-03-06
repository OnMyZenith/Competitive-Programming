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
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << "YES\n";
        for (int i = 1; i <= n * k; i++)
            cout << i << '\n';
        return;
    }
    if (n & 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 1, cnt = 1; i <= n * k; i++) {
        if (i & 1){
            cout << i << " \n"[(cnt++)%k==0];
        }
    }
    for (int i = 1, cnt = 1; i <= n * k; i++) {
        if (!(i & 1)){
            cout << i << " \n"[(cnt++)%k==0];
        }
    }
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    for (int TC = 1; TC <= TT; TC++) {
        solve();
    }

    return 0;
}