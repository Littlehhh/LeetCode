#include<vector>

using std::vector;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(nums.size());
        ans[0]=1;
        for(int i=1; i<n; ++i){
            ans[i] = ans[i-1] * nums[i-1];
        }
        int sufProduct = 1;
        for(int i=n-1; i>=0; --i ){
            ans[i] = sufProduct * ans[i];
            sufProduct *= nums[i];
        }
        return ans;
    }
};
