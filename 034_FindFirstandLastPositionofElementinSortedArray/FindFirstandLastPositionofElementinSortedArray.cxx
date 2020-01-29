#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        if(nums.size() == 1) 
            return target == nums[0] ? vector<int>({0, 0}):vector<int>({-1,-1});
            //  initializer list cannot be used on the right hand side of operator '?'/':'
            // https://stackoverflow.com/questions/11420448/initializer-lists-and-rhs-of-operators
            // return target == nums[0] ? {0, 0} : {-1,-1};
        int lo = 0, hi = nums.size();      
        while( lo < hi ){
            int mid = lo + (hi - lo) / 2;            
            if( nums[mid] < target ) lo = mid + 1;
            else hi = mid;       
        }
        if( lo < nums.size() && target == nums[lo] ) {
            while(++hi < nums.size() && nums[hi] == target);
            return {lo, --hi};
        }
        else return {-1, -1};
    }
};


int main(int argc, char **argv){
    vector<int> nums = {2,2};
    int target = 3;
    Solution s = Solution();
    s.searchRange(nums, target);
}
