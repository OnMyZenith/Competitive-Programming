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
    string s; cin >> s;
    int n = (int)s.size();
    vector<int> ones;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        if(s[i] == '0') {
            if(curr) ones.push_back(curr);
            curr = 0;
        } else {
            curr++;
        }
        if(i == n - 1) {
            if(curr) ones.push_back(curr);
            curr = 0;
        }
    }
    dbg(ones);
    sort(ones.rbegin(), ones.rend());
    int alice = 0;
    for (int i = 0, al = 1; i < (int)ones.size(); i++) {
        if(al) alice += ones[i], al = 0;
        else al = 1;
    }
    cout << alice << '\n';
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