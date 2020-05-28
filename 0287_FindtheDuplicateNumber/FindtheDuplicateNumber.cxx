#include<vector>

using namespace std;

class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        int lo=1, hi=nums.size();
        int mid;
        while(lo < hi){
            int cnt=0;
            mid = lo + (hi-lo) /2;
            for(auto && n : nums){
                if(n <= mid ) 
                    cnt += 1;
            } 
            if(cnt <= mid){
                lo = mid+1;
            }           
            else{
                hi = mid;
            }
        }
        return lo;

    }
};


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        while(true){
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(fast==slow) break;
        }
        slow=0;
        while(true){
            fast=nums[fast];
            slow=nums[slow];
            if(fast==slow) break;
        }
        return fast;
    }
};