#include<vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 对于所有 idx < i : nums[idx < i] = 0
        // j是当前考虑元素的下标
        int p0 = 0, cur = 0;
        // 对于所有 idx > k : nums[idx > k] = 2
        int p2 = nums.size() - 1;

        while (cur <= p2) {
            if (nums[cur] == 0) {
                // 交换第 p0个和第curr个元素
                // i++，j++
                swap(nums[cur++], nums[p0++]);
            }
            else if (nums[cur] == 2) {
                // 交换第k个和第curr个元素
                // p2--
                swap(nums[cur], nums[p2--]);
            }
            else cur++;
        }
    }
};