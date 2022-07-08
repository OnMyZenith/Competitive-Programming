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
    int n; string s; cin >> n >> s;
    string a, b;
    reverse(s.begin(), s.end());
    vector<char> tmp = {'a', 'e', 'i', 'o', 'u'};
    set<char> v(tmp.begin(), tmp.end());
    bool isB = 1;
    for (auto &ch : s) {
        if (isB) b += ch;
        else
            a += ch;
        if (v.count(ch)) isB = !isB;
    }
    reverse(b.begin(), b.end());
    cout << a + b << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    while (TT--) {
        solve();
    }

    return 0;
}