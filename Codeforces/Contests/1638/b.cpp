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
    vector<int> a(n), e, o;
    for (auto &u : a) {
        cin >> u;
        if(u&1) o.push_back(u);
        else e.push_back(u);
    }    
    cout << (is_sorted(e.begin(), e.end()) && is_sorted(o.begin(), o.end()) ? "YES\n" : "NO\n");
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