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

    int n, m;
    cin >> n >> m;
    string S, T;
    cin >> S >> T;

    auto calMinReq = [&](string &s, string &t) -> vector<int> {
        vector<int> p(m + 1);
        for (int i = 0, j = int(find(s.begin(), s.end(), t[0]) - s.begin()); i < m; j = int(find(s.begin() + j + 1, s.end(), t[++i]) - s.begin())) {
            p[i + 1] = j + 1;
        }
        return p;
    };

    auto pre = calMinReq(S, T);
    reverse(S.begin(), S.end());
    reverse(T.begin(), T.end());
    auto suff = calMinReq(S, T);
    reverse(suff.begin(), suff.end());


    int best = 1;
    // T[i - 1], T[i];
    for (int i = 1; i < m; i++) {
        best = max(best, n - (pre[i] + suff[i]) + 1);
    }
    cout << best << '\n';


    return 0;
}
