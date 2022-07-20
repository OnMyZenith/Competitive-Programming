/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif


// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S, vector<int> &C) {
    int n = (int)C.size();
    ll tot = accumulate(C.begin(), C.end(), 0ll);
    for (int i = 0; i < n;) {
        int cnt = 0;
        int mx = 0;
        for (int j = i; j < n && S[j] == S[i]; j++, cnt++) {
            mx = max(mx, C[j]);
        }
        i += cnt;
        tot -= mx;
    }
    return tot;
}








int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    



    return 0;
}
