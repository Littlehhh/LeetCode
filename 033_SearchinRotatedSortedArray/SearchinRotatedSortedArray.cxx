#include<vector>
using namespace std;

class Solution {
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


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        if(nums.size() == 1) return target == nums[0]? 0 : -1;
        auto &&lo = nums.begin(), &&hi = nums.end();      
        if( *nums.begin() > *nums.rbegin()){
            while(lo != hi){
                auto &&mid = lo + distance(lo, hi) / 2;
                if( *mid > *nums.rbegin() ) lo = mid + 1;
                else hi = mid;
            }
            if( target < nums[0] ) hi = nums.end();
            else lo = nums.begin();
        }
        while( lo != hi ){
            auto &&mid = lo + distance(lo, hi) / 2;            
            if( *mid < target ) lo = mid + 1;
            else hi = mid;       
        }
        if( lo != nums.end() && target == *lo ) return distance(nums.begin(),lo);
        else return -1;
    }
};