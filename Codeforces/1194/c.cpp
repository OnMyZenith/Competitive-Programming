/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

// Because multiset.erase(t) will erase all occurances of t!!
template <class T, class U> bool erase(T &t, const U &u) {
    auto it = t.find(u);
    if (it == end(t)) return false;
    t.erase(it); return true;
}

void solve() {
    string s, t, p; cin >> s >> t >> p;
    int n = (int)s.size();
    int m = (int)t.size();
    multiset<char> res(p.begin(), p.end());
    int i = 0;
    for (int j = 0; j < m; j++) {
        if (i < n && s[i] == t[j]) i++;
        else if (res.count(t[j])) {
            erase(res, t[j]);
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << (i == n ? "YES" : "NO") << '\n';
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