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

int main() {
    vamos;

    int d; cin >> d;
    if(d & 1) {
        cout << "-1\n"; return 0;
    }
    d /= 2;
    cout << "0 " << d << '\n';
    cout << "0 " << -d << '\n';
    cout << d << " 0" << '\n';
    cout << -d << " 0" << '\n';

    return 0;
}