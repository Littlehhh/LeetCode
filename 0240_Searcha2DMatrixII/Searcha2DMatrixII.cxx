#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // pick the left-bottom as start point
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        int row = matrix.size()-1;
        int col = 0;
        while(row >= 0 && col < matrix[0].size()){
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) col++;
            else if(matrix[row][col] > target) row--;

        }
        return false;
    }
};