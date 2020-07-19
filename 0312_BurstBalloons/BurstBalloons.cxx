#include<vector>

using namespace std;

class Solution {
public:
    
    vector<vector<int>> cache;
    int maxCoins(vector<int>& nums) {
        if( nums.size() == 0) return 0;
        cache = vector<vector<int>>(nums.size(), vector<int>(nums.size(), -1));
        return maxCoins(0, nums.size()-1, nums);
    }
    
    int maxCoins(int l, int r, vector<int>& nums){
        if(l<=r)
        if(cache[l][r] != -1) return cache[l][r];
        
        if(l == r){
            int left = l-1>=0?nums[l-1]:1;
            int right = r+1<nums.size()?nums[r+1]:1;
            return left * nums[l] * right;
        }
        
        int ans = 0;

        for(int i=l; i<=r; ++i){
            int left = l-1>=0?nums[l-1]:1;
            int right = r+1<nums.size()?nums[r+1]:1;
            int tmp = maxCoins(l, i-1, nums) + left*nums[i]*right + maxCoins(i+1, r, nums);
            ans = max(ans, tmp);
        }
        if(r>=l)
        cache[l][r] = ans;

        return ans;
    }
};


