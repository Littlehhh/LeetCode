#include<climits>

using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0 || divisor == 0) return 0;
        if(divisor == INT_MIN) return dividend == INT_MIN ? 1:0;
        if(divisor == -1) return dividend == INT_MIN ? INT_MAX : -dividend; 
        if(divisor == 1) return dividend; 
        bool sign = dividend > 0 == divisor > 0; 
        if(dividend > 0) dividend = -dividend; 
        if(divisor < 0) divisor = -divisor;
        int ans = 0;
        while(-divisor >= dividend){ // because negetive
            int tmp = divisor;
            int i = 1;
            while( tmp<<1 > 0 && -(tmp<<1) >= dividend){
                tmp <<= 1;
                i <<= 1;
            }
            ans += i;
            dividend += tmp; 
        }
        return sign? ans:-ans;
    }
};