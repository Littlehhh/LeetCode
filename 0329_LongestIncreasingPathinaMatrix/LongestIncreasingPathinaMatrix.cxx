#include<vector>

using namespace std;

class Solution {
public:
    int m,n;
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        m = matrix.size();
        n = matrix[0].size();        
        auto memo = vector< vector<int> > (m, vector <int> (n, 0));
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                ans = max(dfs(i, j, matrix, memo), ans);
            }
        }

        return ans;
    }

    int dfs(int r, int c, vector< vector<int> > &matrix, vector< vector<int> > &memo){
        if(memo[r][c]) return memo[r][c];
        ++memo[r][c];
        for(int i=0; i<4; ++i){
            int nr = r+dirs[i][0], nc = c+dirs[i][1];
            if(checkEdge(nr, nc) && matrix[nr][nc]>matrix[r][c]){
                memo[r][c] = max(memo[r][c], dfs(nr, nc, matrix, memo)+1);
            }
        }

        return memo[r][c];
    }
    bool checkEdge(int r, int c){
        return r>=0 && r<m && c>=0 && c<n;
    }
};

