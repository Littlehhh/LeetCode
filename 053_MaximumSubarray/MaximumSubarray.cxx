#include<vector>
using std::vector;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 0) return 0;
        int ans = nums[0];
        int cur_max = nums[0];
        for(int i=1; i<nums.size(); ++i){
            cur_max = std::max(nums[i], cur_max+nums[i]);
            ans = std::max(cur_max, ans);
        }
        return ans;
    }
};