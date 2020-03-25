#include<vector>

using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int sum = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                int level = grid[i][j];
                if(level > 0){
                    sum += (level << 2) + 2;
                    // 一个柱体中：2个底面 + 所有的正方体都贡献了4个侧表面积 
                    // 减掉 i 与 i-1 相贴的两份表面积
                    sum -= i > 0? min(level, grid[i - 1][j]) << 1: 0; 
                    // 减掉 j 与 j-1 相贴的两份表面积
                    sum -= j > 0? min(level, grid[i][j - 1]) << 1: 0;
                }
            }
        }
        return sum;
    }
};

