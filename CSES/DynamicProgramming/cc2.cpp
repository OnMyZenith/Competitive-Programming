#include <bits/stdc++.h>
using namespace std;
const int tasz = 1e6+007;
int x[101];
int dp[101][tasz];
int main() {
#ifdef asr
    auto begin = chrono::high_resolution_clock::now();
#endif

    int mod = 1e9 + 7;
    int n, target;
    cin >> n >> target;
    // for (int i = 0; i < n; i++)
    //     cin >> x[i];
    vector<int> x(n);
    for (int &v : x)
        cin >> v;

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            
            dp[i][j] = dp[i - 1][j];
            
            if (j - x[i - 1] >= 0) (dp[i][j] += dp[i][j - x[i - 1]]) %= mod;
            
        }
    }
    cout << dp[n][target] << endl;

#ifdef asr
    auto end = chrono::high_resolution_clock::now();
    cout << setprecision(2) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end - begin).count() * 1000 << " ms" << endl;
#endif
}