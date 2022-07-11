/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

// Manacher's Algorithm for all odd palindromic substirngs in O(n);
vector<int> manacher_odd(string s) {
    int n = (int)s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

// Returns an int array of length 2n - 1, where
// Odd i represents even length palindromes, and vice versa
vector<int> manacher(const string &s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");

    for (int i = 1; i < (int)res.size() - 1; i++) {
        res[i] /= 2;
        if (i & 1) res[i] = res[i] * 2 - 1;
        else res[i] *= 2;
    }
    return vector<int>(begin(res) + 1, end(res) - 1);
}

// Manacher Combined for even and odd lengths
// p[1] -> odd & len = 2 * p[1][i] + 1 & starts at i - p[1][i];
// p[0] -> even & len = 2 * p[1][i] & starts at i - p[1][i]; (even 'center' is the just right char)
vector<vector<int>> manacher_combined(const string &s) {
    vector<vector<int>> p(2, vector<int>((int)s.size(), 0));
    for (int z = 0, l = 0, r = 0, n = (int)s.size(); z < 2; z++, l = 0, r = 0) {
        for (int i = 0; i < n; i++) {
            if (i < r) p[z][i] = min(r - i + !z, p[z][l + r - i + !z]);
            int L = i - p[z][i], R = i + p[z][i] - !z;
            while (L - 1 >= 0 && R + 1 < n && s[L - 1] == s[R + 1])
                p[z][i]++, L--, R++;
            if (R > r) l = L, r = R;
        }
    }

    return p;
}

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    string s; cin >> s;
    // auto v = manacher(s);
    auto v = manacher_combined(s);
    int best = 0;
    int start = -1;
    dbg(v);
    for (int i = 0; i < (int)s.size(); i++) {
        for (int x : {0, 1}) {
            if (ckmax(best, 2 * v[x][i] + x)) {
                start = i - v[x][i];
            }
        }
    }
    dbg(start, best);
    cout << s.substr(start, best) << '\n';

    return 0;
}