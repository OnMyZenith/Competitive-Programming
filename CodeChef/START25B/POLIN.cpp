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
    set<int> s1, s2;
    for (int i = 0; i < n; i++){
        int x,y; cin >> x>>y;
        s1.insert(x);
        s2.insert(y);
    }
    cout << ((int)s1.size()) + ((int)s2.size()) << '\n';


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