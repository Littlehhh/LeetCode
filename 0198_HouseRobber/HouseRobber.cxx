#include<vector>

using std::vector;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return std::max(nums[0], nums[1]);

        nums[2] += nums[0];
        for(int i=3; i < nums.size(); ++i){
            nums[i] += std::max(nums[i-2], nums[i-3]);
        }
        return std::max(*nums.rbegin(), *(nums.rbegin()+1));
    }
};
