#include<vector>

using namespace std;

class Solution {
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