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


int solution(int K, vector< vector<int> > &A) {
    const int inf = 1e9;
    int n = (int)A.size();
    int m = (int)A[0].size();
    int c1 = inf, c2 = inf, c3 = inf, c4 = inf;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j]) {
                int x = j;
                int y = n - 1 - i;

                if (c1 == inf) {
                    c1 = y + K - x;
                    c2 = y - K - x;
                    c3 = y - K + x;
                    c4 = y + K + x;
                } else {
                    c1 = min(c1, y + K - x);
                    c2 = max(c2, y - K - x);
                    c3 = max(c3, y - K + x);
                    c4 = min(c4, y + K + x);
                }
            }
        }
    }
    if (c2 > c1 || c3 > c4) {
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = j;
            int y = n - 1 - i;

            if (y - x <= c1 && y - x >= c2 && x + y >= c3 && x + y <= c4) {
                ans += !A[i][j];
            }
        }
    }
    return ans;
}








int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    



    return 0;
}
