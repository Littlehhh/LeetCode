#include<iostream>
#include<queue>
#include<vector>

using namespace std;

static const auto io_sync_off = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        if(grid.size()==0 || grid[0].size() == 0) return -1;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        queue< pair<int, int> > q;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    q.push({i,j});
                }
            }
        }

        if(q.empty() || q.size() == grid.size() * grid[0].size()) return -1;
        pair<int, int> index;
        while(!q.empty()){
            index = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int x = index.first + dx[i];
                int y = index.second + dy[i];
                if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 0) {
                    continue;
                }
                grid[x][y] = grid[index.first][index.second] + 1; 
                q.push({x,y});
            }
        }
        return grid[index.first][index.second] -1;

    }
};
