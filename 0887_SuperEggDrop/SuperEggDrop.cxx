#include<vector>

using std::vector;

class Solution {
public:
    int superEggDrop(int K, int N) 
    {
        vector<int> dp(K+1, 0);
        int m = 0;
        for (; dp[K] < N; ++m) 
            for (int i = K; i >= 1; --i) 
                dp[i] += 1 + dp[i - 1];
        return m;
    }
};