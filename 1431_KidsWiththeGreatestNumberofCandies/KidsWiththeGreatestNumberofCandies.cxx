#include<vector>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        if(candies.size() == 0 ) return {};
        int greatest = *max_element(candies.begin(), candies.end());
        vector<bool> ans(candies.size(), true);
        for(auto && candy:candies){
            if(candy+extraCandies < greatest)
                ans[distance(&candies[0], &candy)] = false;
        }
        return ans;
    }
};