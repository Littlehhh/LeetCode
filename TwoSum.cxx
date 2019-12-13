#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> Map;
        for (int i = 0; i != nums.size(); ++i) {
            auto found = Map.find(nums[i]);
            if (found != Map.end())
                return {found->second, i};
            Map.emplace(target - nums[i], i);
        }
        return {-1, -1};
    }
};