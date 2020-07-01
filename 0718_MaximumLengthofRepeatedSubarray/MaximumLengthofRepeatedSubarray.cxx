#include<vector>
#include<iostream>
using namespace std;

static const auto io_sync_off = []{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   return nullptr; 
}();

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int ans=0;
        int m = A.size();
        int n = B.size();
        if(!m || !n) return 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1, 0));
        
        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                if(A[i-1] == B[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;

    }
};