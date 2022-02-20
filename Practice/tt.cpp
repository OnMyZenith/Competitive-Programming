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

// class Solution {
// public:
//     int maxArea(vector<int> &height) {
//         vector<array<int, 2>> left, right;
//         int n = (int)height.size();
//         left.reserve(n);
//         right.reserve(n);
//         left.push_back({height.front(), 0});
//         right.push_back({height.back(), n - 1});
//         for (int i = 0; i < n; i++) {
//             if (height[i] > left.back()[0]) left.push_back({height[i], i});
//         }
//         for (int i = n - 1; i >= 0; i--) {
//             if (height[i] > right.back()[0]) right.push_back({height[i], i});
//         }
//         int best = 0;
//         for (auto &[yl, xl] : left) {
//             for (auto &[yr, xr] : right) {
//                 best = max(best, min(yl, yr) * (xr - xl));
//                 if (yl < yr || xr <= xl) break;
//             }
//         }
//         return best;
//     }
// };

// int main() {
//     Solution s;
//     vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
//     vector<int> v1 = {2, 3, 4, 5, 18, 17, 6};
//     cout << s.maxArea(v) << '\n';
//     cout << s.maxArea(v1) << '\n';
//     return 0;
// }

class Solution {
public:
    int res[101][129][2];
    bool ok[101][129][2] = {false};
    int pre[101];
    int sg(vector<int> &piles, int idx, int M, bool turnAlice) {
        if(idx == ((int)piles.size())) return 0;
        if(ok[idx][M][turnAlice]) return res[idx][M][turnAlice];

        int mn = sg(piles, idx + 1, max(1, M), !turnAlice) + piles[idx];
        int mx = mn;
        for (int x = 2; x <= 2 * M && idx + x < ((int)piles.size()); x++) {
            int points = sg(piles, idx + x, max(x, M), !turnAlice) + pre[idx + x] - pre[idx];
            mn = min(points, mn);
            mx = max(points, mx);
        }
        ok[idx][M][turnAlice] = 1;
        dbg(mn, mx, idx, M, turnAlice);
        if(turnAlice) {
            return res[idx][M][turnAlice] = mx;
        }
        return res[idx][M][turnAlice] = mn;
    }

    int stoneGameII(vector<int>& piles) {
        memset(ok, 0, sizeof(ok));
        pre[0] = 0;
        for (int i = 0; i < ((int)piles.size()); i++) pre[i + 1] = pre[i] + piles[i];
        return sg(piles, 0, 1, true);
    }
};

int main() {
    Solution s;
    vector<int> v = {2,7,9,4,4};
    vector<int> v1 = {1,2,3,4,5,100};
    cout << s.stoneGameII(v) << '\n';
    cout << s.stoneGameII(v1) << '\n';
    return 0;
}

// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = (int) matrix.size();
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 // swap (1, 2) then (1, 3) then (1, 4)

//             }
//         }
//     }
// };



