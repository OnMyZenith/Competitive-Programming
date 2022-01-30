#include "home.hpp"

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> score(n+1), pre0(n), suff1(n), res;
        for (int i = 0; i < n; i++){
            pre0[i] = (i?pre0[i-1]:0) + (nums[i]==0);
        }
        for (int i = n - 1; i >= 0; i--){
            suff1[i] = ((i!=n-1)?suff1[i + 1]:0) + (nums[i]==1); 
        }
        for (int i = 0; i <= n; i++){
            score[i] = (i?pre0[i-1]:0) + ((i!=n)?suff1[i]:0);
        }
        int m = *max_element(score.begin(), score.end());

        for (int i = 0; i <= n; i++){
            if(score[i]==m) res.push_back(i);
        }
        return res;

    }
};

// class Solution {
// public:
//     int findFinalValue(vector<int>& nums, int original) {
//         auto it = find(nums.begin(), nums.end(),original);
//         while(it!=nums.end()){
//             original*=2;
//             it = find(nums.begin(), nums.end(),original);
//         }
//         return original;
//     }
// };




int main() {
    vamos; fix(15);
    cin.tie(nullptr);

    Solution s;


    return 0;
}