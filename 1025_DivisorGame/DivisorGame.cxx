#include<vector>
using std::vector;

class Solution {
public:
    bool divisorGame(int N) {
        vector<int> dp(N+1, 0);
        dp[0] = 0;
        dp[1] = 0;

        for(int i=2; i<=N; ++i){
            for(int j=1; j<=i/2; j++){
                if(i%j == 0 && dp[i-j]==0){
                    dp[i]=1; break;
                }
            }
        }
        return dp[N];
    }
};