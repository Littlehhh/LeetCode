#include<vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int maxF = nums[0], minF = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if(nums[i] < 0) swap(maxF, minF);
            maxF = max(maxF * nums[i], nums[i]);
            minF = min(minF * nums[i], nums[i]);
            ans = max(maxF, ans);
        }
        return ans;
    }
};

