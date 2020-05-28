#include<vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
    void CountingSort(vector<int>& nums){
        int min = INT_MAX, max = INT_MIN;
        for(auto && num:nums){
            min = std::min(num, min);
            max = std::max(num, max);
        }
        vector<int> counter(max-min+1);
        for (int num: nums) {
            counter[num - min]++;
        }
        int idx = 0;
        for (int num = min; num <= max; num++) {
            int cnt = counter[num - min];
            while (cnt-- > 0) {
                nums[idx++] = num;
            }
        }
    }
};
