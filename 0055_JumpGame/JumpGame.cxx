#include<vector>

using std::vector;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return true;
        int maxPos = 0;
        int end = 0;
        for(int i=0; i < nums.size()-1; ++i){
            maxPos = std::max(maxPos, nums[i]+i);
            if(i > end) return false;
            if(maxPos >= nums.size()-1) return true;
            if(i == end){
                end = maxPos;
            }
        }
        return false;
    }
};