#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if( !(m&&n) ) return {};
        if(m > n) return intersect(nums2, nums1);
        vector<int> ans;
        unordered_map<int, int> dict;
        for( auto n:nums1){
            dict[n]++;
        }
        for( auto n:nums2){
            if(dict.count(n) && dict[n] > 0){
                ans.push_back(n);
                dict[n]--;       
            }
        }
        return ans;
    }
};