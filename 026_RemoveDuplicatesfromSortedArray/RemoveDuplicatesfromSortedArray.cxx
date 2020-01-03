#include<vector>
#include<iostream>
#include<set>
using namespace std;

static auto x = []() {ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL; }();

class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> ans(nums.begin(), nums.end());
        nums.assign(ans.begin(), ans.end());
        return ans.size();
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        auto lo = nums.begin();
        for(auto && hi: nums){
            if(*lo != hi) {                
                ++lo;
                *lo = hi;
            }
        }
        return distance(nums.begin(), ++lo);
    }
};