#include<vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=0, hi=nums.size()-1;
        int mid;
        while(lo<hi){
           mid = lo + (hi-lo) / 2;
           if(nums[mid] > nums[hi]){
               lo = mid +1;
           } 
           else if(nums[mid] > nums[lo]){
               hi = mid;
           }
           else hi--;
        }
        return nums[lo];
    }
};