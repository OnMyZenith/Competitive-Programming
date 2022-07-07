/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

// for s[:i], pi[i] = length of longest proper prefix thats also a suffix, i.e. s[:pi[i] - 1] == s[i - (pi[i] - 1):]
vector<int> prefix_function(const string &s) {
    int n = (int)s.size();
    vector<int> pi(n);
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

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


void solve() {
    int n; string s; cin >> n >> s;
    vector<int> a(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i], a[i]--; p[a[i]] = i;
    }
    ll _lcm = 1;
	vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
        int curr = i; string t;
		vis[i] = 1;
        do {
            curr = a[curr], t += s[curr]; vis[curr] = 1;
        } while (curr != i);
        // int cnt = 0;
        // string r = t;
        // do {
        //     rotate(t.begin(), t.begin() + 1, t.end());
        //     cnt++;
        // } while (r != t);
        auto pi = prefix_function(t);
        auto zv = z_function(t);
        int m = (int)t.size();
        zv[0] = m;
        int j = pi[m - 1];
        dbg(zv, pi);
        while (1) {
            if (zv[j] == m - j) {
                dbg(zv[j], j);
                _lcm = lcm(_lcm, m - j);
                break;
            }
            j = pi[j - 1];
        }
    }
	cout << _lcm << '\n';
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