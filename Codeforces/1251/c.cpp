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
    // vector<int> idx(n); iota(idx.begin(), idx.end(), 0);
    // sort(idx.begin(), idx.end(), [&](int &i, int &j) -> bool {
    //     if (((s[i] - 'a') & 1) == ((s[j] - 'a') & 1)) return i < j;
    //     return s[i] < s[j];
    // });
    // string res(n, '0');
    // for (int i = 0; i < n; i++) res[i] = s[idx[i]];
    // cout << res << '\n';


    vector<char> odd, even;
    odd.reserve(n), even.reserve(n);
    for (int i = 0; i < n; i++) {
        if((s[i] - 'a') & 1) odd.emplace_back(s[i]);
        else even.emplace_back(s[i]);
    }

    string res;
    int N = (int)odd.size(), M = (int)even.size();
    int i = 0, j = 0;
    while (i < N && j < M) {
        if (odd[i] < even[j]) {
            res += odd[i++];
        } else if (even[j] < odd[i]) {
            res += even[j++];
        } else {
            // int _i = i, _j = j;
            // while (_i < N && _j < M && odd[_i] != even[_j]) ++_i, ++_j;
            assert(false);
        }
    }
    while (i < N) res += odd[i++];
    while (j < M) res += even[j++];
    cout << res << '\n';


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