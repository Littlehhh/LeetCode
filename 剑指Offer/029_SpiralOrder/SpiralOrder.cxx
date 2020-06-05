#include<vector>

using std::vector;

class Solution1 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if( matrix.size() == 0 ) return {};
        if( matrix.size() == 1 ) return matrix[0]; 
        int col_status[] = {1,0,-1,0};
        int row_status[] = {0,1,0,-1};
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = 0;
        int m_c = m-1;
        int n_c = n-1;
        while(row < m-1 && col < n-1){
            for( int status = 0; status < 4; ++status ){
                int tmp = status & 1 ? m_c : n_c;
                while(tmp--){   
                    ans.push_back(matrix[row][col]);
                    row += row_status[status];
                    col += col_status[status];
                }
            }
            row++;
            col++;
            m--;
            n--;
            m_c-=2;n_c-=2;
        }
        while(row < m-1 && col == n-1){
            ans.push_back(matrix[row++][col]);
        }
        while(col < n-1 && row == m-1){
            ans.push_back(matrix[row][col++]);
        }
        if(row==m-1 && col==n-1 ) ans.push_back(matrix[row][col]);
        return ans;
    }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }
        vector<int> ans(matrix.size() * matrix[0].size());
        int up = 0, down = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        int idx = 0;
        while (true) {
            for (int i = left; i <= right; i++) {
                ans[idx++] = matrix[up][i];
            }
            if (++up > down) {
                break;
            }
            for (int i = up; i <= down; i++) {
                ans[idx++] = matrix[i][right];
            }
            if (--right < left) {
                break;
            }
            for (int i = right; i >= left; i--) {
                ans[idx++] = matrix[down][i];
            }
            if (--down < up) {
                break;
            }
            for (int i = down; i >= up; i--) {
                ans[idx++] = matrix[i][left];
            }
            if (++left > right) {
                break;
            }
        }
        return ans;
    }
};
