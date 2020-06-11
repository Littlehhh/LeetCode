#include<vector>
#include<cmath>
using namespace std;

class Solution1 {
public:
    int integerBreak(int n) {
        if(n<=3) return n-1;
        int a = n/3;
        int b = n%3;
        if(b==0) return int(pow(3,a));
        if(b==1) return int(pow(3, a-1) * 4);
        return int(pow(3,a) * 2);

    }
};


class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        for(int i=3; i<n+1; ++i){
            for(int j=1; j<i; ++j){
                dp[i] = max(dp[i], max(j*dp[i-j], j*(i-j)));
            }
        }
        return dp[n];
    }
};
