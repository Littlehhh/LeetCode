#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
        unordered_set<int> used; 
        for(int i = start; i < nums.size(); ++i ){
            auto found = used.find(nums[i]);
            if(found != used.end()) continue;
            else used.insert(nums[i]);
            std::swap(nums[start], nums[i]);
            backtrace(start+1, nums);
            std::swap(nums[start], nums[i]);
        }
    }
    
};