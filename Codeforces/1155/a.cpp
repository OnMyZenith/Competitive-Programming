/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n; cin >> n;
    string s; cin >> s;
    vector<int> first(26, -1);
    pair<int, int> res = {-1, -1};
    for (int i = 0; i < n; i++) {
        if (first[s[i] - 'a'] == -1) first[s[i] - 'a'] = i;
        for (int j = s[i] - 'a' + 1; j < 26; j++) {
            if (first[j] != -1) {
                res = {first[j] + 1, i + 1};
                // res = s.substr(first[j], i - first[j] + 1);
                // reverse(res.begin(), res.end());
                // res = s.substr(0, first[j]) + res + s.substr(i + 1);
                break;
            }
        }
        if (res.first != -1) {
            cout << "YES\n";
            cout << res.first << " " << res.second << '\n';
            return 0;
        }
    }
    cout << "NO\n";

    return 0;
}