#include<vector>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1){
                    int val=0;
                    dfs(grid,i,j,val,m,n);
                    res=max(res,val);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& grid,int i,int j,int& val,int m,int n){
        if(!grid[i][j])return;
        grid[i][j]=0;
        val++;
        if(i-1>=0)dfs(grid,i-1,j,val,m,n);
        if(i+1<m)dfs(grid,i+1,j,val,m,n);
        if(j-1>=0)dfs(grid,i,j-1,val,m,n);
        if(j+1<n)dfs(grid,i,j+1,val,m,n);
    }
};