#include<vector>

using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0 || divisor == 0) return 0;
        if(divisor == INT_MIN) return dividend == INT_MIN ? 1:0;
        bool sign = dividend > 0 == divisor > 0; 
        if(dividend > 0) -dividend; 
        if(divisor < 0 ) -divisor;
        vector<int> divisors;
        divisors.clear();
        int ans = 0;
        while(-divisor >= dividend){ // because negetive
            divisors.push_back(divisor);
            cout << divisor << " ";
            divisor <<= 1;
        }
        return ans;
    }
};