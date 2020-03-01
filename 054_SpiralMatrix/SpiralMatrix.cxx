#include<vector>

using std::vector;

class Solution {
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
        while(row < m-1 && col < n){
            ans.push_back(matrix[row++][col]);
        }
        while(col < n-1 && row < m){
            ans.push_back(matrix[row][col++]);
        }
        if(row==m-1 && col==n-1 ) ans.push_back(matrix[row][col]);
        return ans;
    }
};