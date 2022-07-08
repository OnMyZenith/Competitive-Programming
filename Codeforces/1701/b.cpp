/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


void solve() {
    int n; cin >> n;
    cout << "2\n";
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    set<int> s(a.begin(), a.end());

    cout << *s.begin() << ' ';
    s.erase(s.begin());
    int l = 1;

    while (s.size()) {
        auto it = s.lower_bound(2 * l);
        if (it != s.end() && *it == 2 * l) {
            cout << *it << ' ';
            l *= 2;
            s.erase(it);
        } else {
            cout << *s.begin() << ' ';
            l = *s.begin();
            s.erase(s.begin());
        }
    }
    cout << '\n';
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