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

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

const int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1}; // URDL
const char dir[4] = {'U', 'R', 'D', 'L'};

int n, m;
int cost[507][507][4];
bool ok[507][507][11];
int dp[507][507][11];

int best(int r, int c, int steps) {
    if(r < 0 || r >= n || c < 0 || c >= m) return 1e9;
    if(!steps || ok[r][c][steps]) return dp[r][c][steps];

    dp[r][c][steps] = 1e9;
    for (int k = 0; k < 4; k++) {
        ckmin(dp[r][c][steps], cost[r][c][k] + best(r + dr[k], c + dc[k], steps - 1));
    }
    ok[r][c][steps] = 1;
    return dp[r][c][steps];
}

int main() {
    vamos;

    int k; cin >> n >> m >> k;
    
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m - 1; c++) {
            cin >> cost[r][c][1];
            cost[r][c + 1][3] = cost[r][c][1];
        }
    }
    for (int r = 0; r < n - 1; r++) {
        for (int c = 0; c < m; c++) {
            cin >> cost[r][c][2];
            cost[r + 1][c][0] = cost[r][c][2];
        }
    }

    if(k & 1) {
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                cout << -1 << " \n"[c == m - 1];
            }
        }
        return 0;
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            best(r, c, k / 2);
            cout << 2 * dp[r][c][k / 2] << " \n"[c == m - 1];
        }
    }

    return 0;
}