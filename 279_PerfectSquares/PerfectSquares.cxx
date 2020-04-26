#include<vector>
#include<cmath>

using namespace std;

class Solution1 {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX-1);
        int max_square_index = sqrt(n) + 1;
        vector<int> square(max_square_index, 0);
        dp[0] = 0;
        for(int i=0; i<max_square_index; ++i){
            square[i] = i * i;
        }
        for(int i=1; i<=n; ++i){
            for (int s = 1; s < max_square_index; ++s){
                if( i < square[s] ) break;
                dp[i] = min(dp[i], dp[i-square[s]]+1);
            }
            
        }
        return dp[n];
    }
};
class Solution {
private:
    bool isSquare(int n) {
        int m = sqrt(n);
        return m * m == n;
    }
public:
    int numSquares(int n) {
        while(n % 4 == 0)
            n /= 4;
        if ((n & 7) == 7)
            return 4;
        if (isSquare(n))
            return 1;
        for (int i = 1; i * i < n; ++i) {
            if (isSquare(n - i * i))
                return 2;
        }
        return 3;
    }
};