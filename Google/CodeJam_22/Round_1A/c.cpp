/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif




void solve(int _TC) {
    int n, w; cin >> n >> w;
    vector<vector<int>> E(n, vector<int>(w + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> E[i][j];
        }
    }

    vector<vector<vector<int>>> A(n);

    for (int i = 0; i < n; i++) {
        vector<int> x;
        for (int j = 1; j <= w; j++) {
            for (int k = 0; k < E[i][j]; k++) {
                x.push_back(j);
            }
        }
        do {
            A[i].push_back(x);
        } while (next_permutation(x.begin(), x.end()));
    }
    




    cout << "Case #" << _TC << ": ";

}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    for (int TC = 1; TC <= TT; TC++) {
        solve(TC);
    }

    return 0;
}