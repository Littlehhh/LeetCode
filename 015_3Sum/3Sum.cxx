#include<vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector< vector<int> > ans;
        auto num = nums.begin();
        while(num != nums.end()){
            auto lo = num + 1;
            auto hi = nums.end()-1;
            if(*num > 0) break;
            while(lo < hi){
                if( *num + *lo + *hi == 0){
                    ans.push_back({*num, *lo, *hi});
                    //jump the repeat condition
                    while(lo+1 != nums.end() && *lo == *(lo+1)){
                        ++lo;
                    }
                    ++lo;
                } 
                else if(*num + *lo + *hi > 0) --hi;
                else ++lo;
            }
            //jump the repeat condition
            while(num+1 != nums.end() && *num == *(num+1)){
                ++num;
            }
            ++num;
        }
        return ans;
    }
};