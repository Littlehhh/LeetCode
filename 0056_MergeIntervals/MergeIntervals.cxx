#include<vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() < 2) return intervals;
        sort(intervals.begin(), intervals.end()); // std::lexicographical_compare
        vector<vector<int>> ans;
        int cur = 0;
        int i = 1;
        while(i < intervals.size()){
            if(intervals[i][0] <= intervals[cur][1]){
                intervals[cur][1] = std::max(intervals[i][1], intervals[cur][1]);  
            }
            else{
                ans.emplace_back(intervals[cur]);
                cur = i;
            }
            ++i;
        }
        ans.emplace_back(intervals[cur]);
        return ans;
    }
};