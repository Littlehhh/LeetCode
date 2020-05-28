#include<vector>
using std::vector;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int lo = 0, hi = nums.size();      
        while( lo < hi ){
            int mid = lo + (hi - lo) / 2;            
            if( nums[mid] < target ) lo = mid + 1;
            else hi = mid;       
        }
        // if( lo < nums.size() && target == nums[lo] ) ;
        // else{
        //     nums.insert(nums.begin()+lo, target);
        // }
        return lo;
    }
};