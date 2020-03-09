#include<vector>
#include<cstddef>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int inf = INT_MAX;
        int minprice = inf, maxprofit = 0;
        for (int price: prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(price, minprice);
        }
        return maxprofit;
    }
};
