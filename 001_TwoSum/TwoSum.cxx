#include<vector>
#include<unordered_map>


class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> HashMap;
        for (int i = 0; i != nums.size(); ++i) {
            auto found = HashMap.find(nums[i]);
            if (found != HashMap.end())
                return {found->second, i};
            HashMap.emplace(target - nums[i], i);
        }
        return {-1, -1};
    }
};
