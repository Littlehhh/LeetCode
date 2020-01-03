#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        auto lo = nums.begin();
        for(auto hi = nums.begin(); hi != nums.end();  ++hi){ 
            if(*hi == val)
                continue;
            else{
                *lo = *hi;
                ++lo;
            }            
        }
        return distance(nums.begin(), lo);
    }
};