#include<vector>

using namespace std;

// backtrace v1 bad solution
class Solution1 {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size() == 0) return 0;
        sort(coins.begin(), coins.end(), greater<int>());
        int count = coinChange(0, amount, coins);
        return count >= 0 ? count : -1;
    }
    int coinChange(int count, int amount, vector<int> &coins){
        if(amount == 0)  return count;
        if(amount < 0)  return -1;
        for(auto && coin:coins){
            int tmp = coinChange(count+1, amount-coin, coins);
            if( tmp != -1){
                count = min(tmp, count);
            } 
        }
        return count;  
    }
};

// backtrace + prune 
class Solution2 {
public:
    void coinChange(int& ans, int count, int index, int amount, vector<int>& coins){
        if(amount == 0){
            ans = min(ans, count);
            return;
        }
        if(index == coins.size()) return;
        for( int i = amount / coins[index]; i>=0 && count + i < ans; --i){
            coinChange(ans, count+i, index+1, amount-i*coins[index], coins);
        }
        return;
    }

    int coinChange(vector<int>& coins, int amount)
    {
        if (amount == 0) return 0;
        sort(coins.begin(), coins.end(), greater<int>());
        int ans = INT_MAX;
        coinChange(ans, 0, 0, amount, coins);
        return ans == INT_MAX ? -1 : ans;
    }
};

// dp bottom to up
class Solution3 {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 数组大小为 amount + 1，初始值也为 amount + 1
        vector<int> dp(amount + 1, amount + 1);
        // base case
        dp[0] = 0;
        for (int i = 0; i < dp.size(); i++) {
            // 内层 for 在求所有子问题 + 1 的最小值
            for (int coin : coins) {
                if (i - coin >= 0)
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};
// dp up to bottom
class Solution {
public:
    int coinChange(int rem, vector<int>& coins, vector<int>& count) {
        if (rem < 0) return -1;
        if (rem == 0) return 0;
        if (count[rem] != INT_MAX) return count[rem];
        int tmp = INT_MAX;
        for (auto &&coin:coins) {
            int res = coinChange(rem - coin, coins, count);
            if (res >= 0 && res < tmp) {
                tmp = res + 1;
            }
        }
        count[rem] = tmp == INT_MAX ? -1 : tmp;
        return count[rem];
    }

    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;
        vector<int>count(amount + 1, INT_MAX);
        count[0] = 0;
        int res = coinChange(amount, coins, count);
        return res == INT_MAX ? -1 : res;
    }
};

