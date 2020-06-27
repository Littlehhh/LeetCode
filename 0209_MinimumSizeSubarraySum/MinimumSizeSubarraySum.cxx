#include<vector>
#include<climits>

using namespace std;

class Solution1 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start=0, end=0;
        int ans = INT_MAX;
        int sum = 0;
        while(end < nums.size()){
            sum+=nums[end++];
            while(sum >= s){
                ans = min(end-start, ans);
                sum -= nums[start++];
            }

        }
        return ans == INT_MAX ? 0: ans;
    }
};

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        vector<int> sums(n + 1, 0); 
        // 为了方便计算，令 size = n + 1 
        // sums[0] = 0 意味着前 0 个元素的前缀和为 0
        // sums[1] = A[0] 前 1 个元素的前缀和为 A[0]
        // 以此类推
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            int target = s + sums[i - 1];
            auto bound = lower_bound(sums.begin(), sums.end(), target);
            if (bound != sums.end()) {
                ans = min(ans, static_cast<int>((bound - sums.begin()) - (i - 1)));
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};


