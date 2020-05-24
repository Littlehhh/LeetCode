#include<vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size()==0 || matrix[0].size() == 0) return;
        int row = matrix.size();
        int col = matrix[0].size();
        
        // use matrix[0][0] as row 0 have 0 flag
        // use col_0 as col 0 have 0 flag
        bool col_0 = false;
        
        // check 0
        for(int i=0; i<row; ++i){
            if(matrix[i][0] == 0) col_0 = true;
            for(int j=1; j<col; ++j){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        // set 0 except 0row 0col
        for(int i=1; i<row; ++i){
            for(int j=1; j<col; ++j){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        // set 0th row
        if(matrix[0][0] == 0)
            for(int j=1; j<col; ++j){
                matrix[0][j] = 0;
            }
                
        // set 0th col
        if(col_0 == true)
            for(int i=0; i<row; ++i){
                matrix[i][0] = 0;
            }
        return;
    }
};