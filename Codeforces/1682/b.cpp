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
    vector<int> a(n), where(n);
    set<int> bad;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        where[a[i]] = i;
        if(a[i] != i) bad.insert(a[i]);
    }

    int res = (1 << 29) - 1;
    dbg(where);
    while(!bad.empty()) {
        dbg(bad);
        int x = *bad.begin();
        vector<int> rem = {x};
        int y = x;
        while(a[x] != y) {
            x = a[x];
            rem.push_back(x);
        }
        dbg(rem);
        for (auto &e : rem) {
            bad.erase(e);
            res &= e;
        }
    }
    



    cout << res << '\n';


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