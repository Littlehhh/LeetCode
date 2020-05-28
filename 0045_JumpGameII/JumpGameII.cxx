#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return 0;
        int step = 0;
        int maxPos = 0;
        int end = 0;
        for(int i=0; i < nums.size()-1; ++i){
            maxPos = std::max(maxPos, nums[i]+i);
            if(maxPos >= nums.size()-1) return ++step;
            if(i == end){
                end = maxPos;
                step++;
            }
        }
        return step;
    }
};