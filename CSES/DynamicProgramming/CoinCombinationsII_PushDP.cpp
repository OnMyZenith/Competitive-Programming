// Push DP gives MUCH FASTER(~100ms) solution because reading d[t] over and over could be done
// using caching, but writing requires real access
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int tasz = 1e6+007;
int coins[101];
int dp[tasz];

int main() {

#ifdef asr
    auto begin = chrono::high_resolution_clock::now();
#endif

    int n, finalTarget;
    cin >> n >> finalTarget;
    for (int i = 0; i < n; i++) cin >> coins[i];
    dp[0] = 1;
    for (int c = 1; c <= n; c++) {
        for (int t = 0; t + coins[c - 1] <= finalTarget; t++){            
            dp[t + coins[c - 1]] += dp[t];
            if (dp[t + coins[c - 1]] >= MOD) 
                dp[t + coins[c - 1]] -= MOD;
        }
    }
    cout << dp[finalTarget] << '\n';

#ifdef asr
    auto end = chrono::high_resolution_clock::now();
    cout << setprecision(2) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count()*1000 << " ms" << endl;
#endif

    return 0;
}