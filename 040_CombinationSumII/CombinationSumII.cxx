#include<vector>

using namespace std;

class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, 0, target, candidates);
        return ans;
    }
    void dfs(int level, int sum, int target, vector<int>& candidates){
        if(sum > target) return;
        if(sum == target) {
            ans.push_back(tmp);
            return;
        }
        for(int i = level; i < candidates.size(); ++i){
            if( i>level && candidates[i] == candidates[i-1]) continue;
            tmp.push_back(candidates[i]);
            dfs(i+1, sum+candidates[i], target, candidates);
            tmp.pop_back();
        }
    }
};