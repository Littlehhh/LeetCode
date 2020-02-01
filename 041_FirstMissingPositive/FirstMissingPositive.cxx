#include<vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==0) return 1;
        if(nums.size() == 1 ) return nums[0] == 1? 2:1;
        bool exist_one = false;
        for(auto && num:nums){
            if(num == 1) exist_one = true;
            if(num <= 0 || num > nums.size()) num = 1;
        }
        if(!exist_one) return 1;
        for(int i=0; i<nums.size(); ++i){
            int tmp = abs(nums[i]) == nums.size() ? 0 : abs(nums[i]);
            if(nums[tmp] > 0) nums[tmp] = -nums[tmp];

        } 
        for( int i = 1; i< nums.size(); ++i){
            if(nums[i] > 0) return i;
        }
        if(nums[0]>0) return nums.size();
        else return nums.size()+1;
    }
};