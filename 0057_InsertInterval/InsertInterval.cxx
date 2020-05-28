#include<vector>

using std::vector;

class Solution1 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0){
            vector<vector<int>> ans;
            ans.emplace_back(newInterval);
            return ans;
        } 
        intervals.emplace_back(newInterval);
        return merge(intervals);  
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() < 2) return intervals;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
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

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        if(intervals.size() == 0){
            vector<vector<int>> ans;
            ans.emplace_back(newInterval);
            return ans;
        } 
        vector<vector<int>> ans;
        int i = 0;
        int cur = -1;
        while(i < intervals.size()){
            if(newInterval[1] < intervals[i][0]){
                ans.emplace_back(newInterval);
                while(i < intervals.size()){
                    ans.emplace_back(intervals[i++]);
                }
                return ans;
            }
            if(newInterval[0] <= intervals[i][1] ){
                intervals[i][1] = std::max(newInterval[1], intervals[i][1]);  
                intervals[i][0] = std::min(newInterval[0], intervals[i][0]);
                cur = i;
                break;
            }
            else{
                ans.emplace_back(intervals[i]);
            }
            ++i;
        }
        if(cur == -1) {
            ans.emplace_back(newInterval);
            return ans;
        }
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
