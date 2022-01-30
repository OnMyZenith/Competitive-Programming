#include "home.hpp"

class Solution {
public:
    int maximumGood(vector<vector<int>> &statements) {
        int n = (int)size(statements);
        int best = 0;
        for (unsigned int mask = 0; mask < (1U << (n)); mask++) {
            bool f = 1;
            for (int i = 0; i < n && f; i++) {
                for (int j = 0; j < n && f; j++) {
                    if (statements[i][j] == 2 || (!((mask >> i) & 1))) continue;
                    if (statements[i][j] == 1) {
                        f &= ((mask >> j) & 1);
                    } else {
                        f &= !((mask >> j) & 1);
                    }
                }
            }
            if (f) best = max(best, __builtin_popcount(mask));
        }
        return best;
    }
};

int main() {
    vamos;
    fix(15);
    cin.tie(nullptr);

    Solution s;
    // vvi v = {{2,0},{0,2}};
    // vvi v = {{2, 1, 2}, {1, 2, 2}, {2, 0, 2}};
    vvi v = {{2, 0, 2, 2, 0}, {2, 2, 2, 1, 2}, {2, 2, 2, 1, 2}, {1, 2, 0, 2, 2}, {1, 0, 2, 1, 2}};
    ps(s.maximumGood(v));

    return 0;
}
// class Solution {
// public:
//     vector<int> findLonely(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size(); vector<int> res;
//         for (int i = 0; i < n; i++){
//             if(i < n - 1 && nums[i]==nums[i+1]) {continue;}
//             if(i > 0 && nums[i]==nums[i-1]) {continue;}
//             bool f = 1;
//             if(i < n - 1 && nums[i] == nums[i+1] - 1) f = 0;
//             if(i > 0 && nums[i - 1] + 1 == nums[i]) f = 0;
//             if(f) res.push_back(nums[i]);
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         vector<int> pos, neg;
//         for(auto ele: nums) if(ele < 0) neg.push_back(ele); else pos.push_back(ele);
//         bool f = 0; reverse(neg.begin(), neg.end()); reverse(pos.begin(),pos.end());
//         for(auto &ele: nums) {
//             if(f) {
//                 ele = neg.back(); neg.pop_back(); f = 0;
//             }else{
//                 ele = pos.back(); pos.pop_back(); f = 1;
//             }
//         }
//         return nums;
//     }
// };

// class Solution {
// public:
//     int countElements(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int x = nums.front(), y = nums.back();
//         while(!nums.empty()&& nums.back()==y) nums.pop_back();
//         reverse(nums.begin(),nums.end());
//         while(!nums.empty()&& nums.back()==x) nums.pop_back();
//         return max(((int)nums.size()), 0);
//     }
// };
