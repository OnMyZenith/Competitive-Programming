/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

// Z[i] is the length of the longest string that is, a prefix of s and a prefix of the suffix of s starting at i.
vector<int> z_function(const string &s) {
    int n = (int)s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) z[i] = min(z[i - l], r - i + 1);

        while (z[i] + i < n && s[z[i] + i] == s[z[i]])
            z[i]++;

        if (i + z[i] - 1 > r) r = i + z[i] - 1, l = i;
    }
    return z;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    string s, t; cin >> s >> t;
    int n = (int)s.size(), m = (int)t.size();
    auto v = z_function(t + '$' + s);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += v[i + 1 + m] == m;
    }
    cout << cnt << '\n';
    return 0;
}