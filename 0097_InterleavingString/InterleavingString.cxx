#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        int m = s1.size(), n = s2.size(), s = s3.size();
        if(m+n != s) return false;

        vector<vector<int> > dp(m+1, vector<int>(n+1, false));
        dp[0][0] = true;
        for(int i=0; i<=m; ++i){
            for(int j=0; j<=n; ++j){
                if( i > 0 ){
                    dp[i][j] |= dp[i-1][j] && s1[i-1]==s3[i+j-1];
                }
                if( j > 0 ){
                    dp[i][j] |= dp[i][j-1] && s2[j-1]==s3[i+j-1];
                }
            }
        }
        return dp[m][n];
    }
};