/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(15) << fixed;

    vector<vector<int>> dp(19, vector<int>(10)); //dp[2][7] = cnt of 7s in 100s place

    for (int i = 0; i < 10; i++) {
        dp[0][i] = 1;
    }
    
    for (int j = 0; j < 19; j++) {
        for (int i = 0; i < 10; i++) {
            dp[j][i] *= 9;
        }
    }

    




    return 0;
}