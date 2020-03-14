#include<vector>

using namespace std;

// dp solution
class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 1);
        for(int i = 0; i < nums.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[j]+1, dp[i]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// greedy + binary search
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int len = nums.size();
        if (len < 2) {
            return len;
        }
        vector<int> tail(nums.size(), 0);
        tail[0] = nums[0];
        int end = 0;
        for (int i = 1; i < len; ++i) {
            if (nums[i] > tail[end]) {
                tail[++end] = nums[i];
            } else {
                int lo = 0;
                int hi = end;
                while (lo < hi) {
                    int mid = lo+(hi-lo)/2;
                    if (tail[mid] < nums[i]) {
                        lo = mid + 1;
                    } else {
                        hi = mid;
                    }
                }
                tail[lo] = nums[i];
            }
        }
        return end+1;
    }
};