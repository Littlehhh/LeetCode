#include<vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if (matrix.empty()) return 0;
        
        vector<vector<int>> m(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        int ans = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '0') continue;
                m[i + 1][j + 1] = min(min(m[i][j + 1], m[i + 1][j]), m[i][j]) + 1;
                ans = max(ans, m[i + 1][j + 1]);
            }
        }

        return ans * ans;
    }

};