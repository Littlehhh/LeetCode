#include<vector>

using namespace std;

class Solution1 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int idx=0;
        vector<int> rowIdx(matrix.size(), 0);
        int ans;
        while(idx < k){
            int minRow = 0;
            int tmpMin = INT_MAX;
            for(int i=0; i<matrix.size(); ++i){
                if( rowIdx[i] < matrix.size() && matrix[i][rowIdx[i]] < tmpMin ){
                    tmpMin=matrix[i][rowIdx[i]];
                    minRow=i;
                }
            }
            rowIdx[minRow]++;
            idx++;
            ans = tmpMin;
        }
        return ans;
    }
};

class Solution {
   public:
    int getAeraSum(const vector<vector<int>>& matrix, const int target){
        int row = matrix.size()-1;
        int col = 0;
        int sum = 0;
        while( row >= 0 && col < matrix.size() ){
            if( matrix[row][col] <= target ){
                sum += row+1;
                ++col;
            }
            else{
                --row;
            }
        }
        return sum;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0];
        int hi = matrix[n - 1][n - 1];
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            if ( getAeraSum(matrix, mid) >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
