#include<vector>

using namespace std;

class Solution {
public:
    int m, n;
    int islandPerimeter(vector<vector<int>>& grid) {
        int sum = 0;
        m = grid.size();
        n = grid[0].size();
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j]){
                    // sum+=4;
                    // sum-=check(i-1,j,grid);
                    // sum-=check(i,j+1,grid);
                    // sum-=check(i,j-1,grid);
                    // sum-=check(i+1,j,grid);
                    return dfs(grid, i, j);
                }
                    
            }
        }
        return sum;
    }
    int check(int i, int j, vector<vector<int>>& grid){
        if(i>=0 && i<m && j>=0 && j<n && grid[i][j] == 1){
            return 1;
        }
        return 0;
    }

    int dfs(vector<vector<int>>& grid, int r, int c){
        if (!(0 <= r && r < m && 0 <= c && c < n)) {
            return 1;
        }
        if (grid[r][c] == 0) {
            return 1;
        }
        if (grid[r][c] != 1) {
            return 0;
        }
        grid[r][c] = 2;
        return dfs(grid, r - 1, c)
            + dfs(grid, r + 1, c)
            + dfs(grid, r, c - 1)
            + dfs(grid, r, c + 1);
    }
};


