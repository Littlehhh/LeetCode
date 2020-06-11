#include<climits>

class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0;
        double ans = 1;
        
        if(n<0) {
            x = 1 / x;
            if(n == INT_MIN){
                ans *= x;
                n = INT_MAX;
            }
            else n = -n;
        }
        while(n>0){
            if(n&1) ans *= x;
            x *= x;
            n>>=1;
        }

        return ans;
    }
};