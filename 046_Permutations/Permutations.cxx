#include<vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) {
            ans.push_back(nums);
            return ans;
        }
        backtrace(0, nums);
        return ans;
    }
    void backtrace(int start, vector<int>& nums){
        if(start == nums.size()){
            ans.push_back(nums);
        } 
        for(int i = start; i < nums.size(); ++i ){
            std::swap(nums[start], nums[i]);
            backtrace(start+1, nums);
            std::swap(nums[start], nums[i]);
        }
    }
};