#include<vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;
        if(nums.size() == 1) return target == nums[0]? true : false;
        auto &&lo = nums.begin(), &&hi = nums.end();      
        auto &&mid = vector<int>::iterator();
        // binary search the rotated pivot
        if( *nums.begin() >= *nums.rbegin()){
            
            while(lo != hi){
                mid = lo + distance(lo, hi) / 2;
                
                if( *mid == target ) return true;
                if( *mid == *lo){
                    lo++;continue;
                } 
                if( *mid > *nums.rbegin() ) lo = mid + 1;
                else hi = mid;
            }
            
            if( target < nums[0] ) hi = nums.end();
            else lo = nums.begin();
        }
        
        // binary search the target
        while( lo != hi ){           
            mid = lo + distance(lo, hi) / 2;
            if( *mid == target ) return true;
            if( *mid < target ) lo = mid + 1;
            else hi = mid;      
        }
        return false;        
    }
};