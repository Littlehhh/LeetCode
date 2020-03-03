#include<vector>
using std::vector;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if( obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) return 0;
        vector<long> ans(obstacleGrid[0].size());
        if(obstacleGrid[0][0] == 1)
            ans[0] = 0;
        else ans[0] = 1;
        for(int i = 1; i < obstacleGrid[0].size(); ++i){
            if(obstacleGrid[0][i] == 1) ans[i] = 0;
            else ans[i] = ans[i-1];
        }

        for(int j = 1; j < obstacleGrid.size(); ++j)
            for(int i=0; i < obstacleGrid[0].size(); ++i){
                if(obstacleGrid[j][i] == 1){
                    ans[i] = 0;
                }
                else{
                    if(i == 0)
                        ans[i] = obstacleGrid[j][i] == 1 ? 0 : ans[i];
                    else 
                        ans[i] = ans[i-1] + ans[i];
                }
            }
        return ans[obstacleGrid[0].size()-1];
    }
};