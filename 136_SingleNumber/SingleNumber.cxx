#include<vector>

using std::vector;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto && n : nums){
            ans ^= n;
        }
        return ans;
    }
};
