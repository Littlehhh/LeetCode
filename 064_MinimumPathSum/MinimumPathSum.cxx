#include<vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int j = 1; j < grid[0].size(); ++j){
            grid[0][j] += grid[0][j-1];
        }
        for(int i = 1; i < grid.size() ; ++i){
            grid[i][0] += grid[i-1][0];
        }
        for(int i = 1; i < grid.size() ; ++i){
            for(int j = 1; j < grid[0].size(); ++j){
                grid[i][j] += std::min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return *(*grid.rbegin()).rbegin();
    }
};