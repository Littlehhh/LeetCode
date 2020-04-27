#include<vector>
using namespace std;

// normal binary search style
class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        if(nums.size() == 1) return target == nums[0]? 0 : -1;
        int lo = 0, hi = nums.size(), end = nums.size()-1;      
        if( nums[0] > nums[end]){
            while(lo < hi){
                int mid = lo + (hi - lo) / 2;
                if( nums[mid] > nums[end] ) lo = mid + 1;
                else hi = mid;
            }
            if( target < nums[0] ) hi = nums.size();
            else lo = 0;
        }
        while( lo < hi ){
            int mid = lo + (hi - lo) / 2;            
            if( nums[mid] < target ) lo = mid + 1;
            else hi = mid;       
        }
        if( lo < nums.size() && target == nums[lo] ) return lo;
        else return -1;
    }
};


// iterator binary search style
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        if(nums.size() == 1) return target == nums[0]? 0 : -1;
        auto &&lo = nums.begin(), &&hi = nums.end();      
        auto &&mid = vector<int>::iterator();
        // binary search the rotated pivot
        if( *nums.begin() > *nums.rbegin()){
            while(lo != hi){
                mid = lo + distance(lo, hi) / 2;
                if( *mid > *nums.rbegin() ) lo = mid + 1;
                else hi = mid;
            }
            if( target < nums[0] ) hi = nums.end();
            else lo = nums.begin();
        }
        // binary search the target
        while( lo != hi ){           
            mid = lo + distance(lo, hi) / 2;
            if( *mid < target ) lo = mid + 1;
            else hi = mid;      
        }
        return lo != nums.end() && target == *lo ? distance(nums.begin(),lo) : -1;
    }
};