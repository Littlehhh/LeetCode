#include<vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans;
        int Min = INT_MAX;
        auto num = nums.begin();
        while(num != nums.end()){
            auto lo = num + 1;
            auto hi = nums.end()-1;
            while(lo < hi){
                int tmp;
                int sum = *num + *lo + *hi; 
                if(  sum > target){
                    tmp = sum - target;
                    --hi;
                } 
                else if(sum < target) {
                    tmp = target - sum;
                    ++lo; 
                }
                else return target;
                if( tmp < Min ) {
                    ans = sum;
                    Min = tmp;
                }
            }
            ++num;
        }
        return ans;
    }
};