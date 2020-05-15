#include<vector>
#include<unordered_map>

using namespace std;
class Solution1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.size(); ++start) {
            int sum = 0;
            for (int end = start; end >= 0; --end) {
                sum += nums[end];
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        int ans = 0;
        unordered_map<int, int> summap;
        summap[0]++;
        int sum = 0;
        for(auto && n:nums){
            sum+=n;
            if(summap.find(sum-k)!= summap.end())
            // if(summap.count(sum-k))
                ans+= summap[sum-k];
            summap[sum]++;
        }
        return ans;
    }
};

