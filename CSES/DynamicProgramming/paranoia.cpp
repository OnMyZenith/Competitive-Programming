#include <iostream>
#include<chrono>
#include<vector>

using namespace std;
const int MOD = 1e9 + 7;
const int tasz = 1e6+007;
int coins[101];
int dp[101][tasz];
int main() {
#ifdef asr
    auto begin = chrono::high_resolution_clock::now();
#endif

    int n, finalTarget;
    cin >> n >> finalTarget;
    // vector<int> coins(n + 1);
    for (int i = 0; i < n; i++) cin >> coins[i];
    // vector<vector<int>> dp(finalTarget + 1, vector<int>(n + 1));
    dp[0][0] = 1;
    for (int c = 1; c <= n; c++) {
        for (int t = 0; t <= finalTarget; t++){
            dp[c][t] = dp[c - 1][t];
            
            if(t - coins[c - 1]>=0)
                dp[c][t] += dp[c][t - coins[c - 1]];

            if (dp[c][t] >= MOD) 
                dp[c][t] -= MOD;
        }
    }
    cout << dp[n][finalTarget] << endl;
#ifdef asr
    auto end = chrono::high_resolution_clock::now();
    // cout << setprecision(2) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count() * 1000 << " ms" << endl;
#endif
    return 0;
}