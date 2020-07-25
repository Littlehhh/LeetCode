#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long lo=INT_MIN, hi = 0;
        for(auto && n:nums){
            hi += n;
            if( lo < n) lo = n;
        }

        while( lo < hi ){
            int mid = lo + (hi-lo) / 2;
            if(CheckArrayNums(nums, m, mid)){
                hi = mid;
            }
            else lo = mid+1;
        }
        return lo;
    }
    bool CheckArrayNums(vector<int>& nums, int m, long long mid){
        long long sum = 0;
        int count = 0;
        for(auto && n:nums){
            if( sum + n > mid){
                count++;
                sum = n;
            }
            else sum+=n;
        }
        count++;
        return count <= m;
    }
};