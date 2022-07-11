/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
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
    for (int i = 1, j; i < n; i++) {
        j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    string s; cin >> s;
    int n = (int)s.size();
    auto pi = prefix_function(s);
    vector<int> res = {pi[n - 1]};

    if (res.back() > 0) while (pi[res.back() - 1] > 0) res.push_back(pi[res.back() - 1]);
    if (res.back() != 0) res.push_back(0);

    for (auto &ele : res) {
        cout << n - ele << " ";
    }
    cout << '\n';

    return 0;
}