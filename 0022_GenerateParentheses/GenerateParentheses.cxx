#include<vector>
#include<string>
using namespace std;

class Solution1 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n == 0) return ans;

        dfs(string(), n, n, ans);    
        return ans;
    }
private:
    void dfs(string curStr, int left, int right, vector<string> &ans){
        if( left == 0 && right == 0){
            ans.push_back(curStr);
            return;
        }
        if(left > 0){
            dfs(curStr+"(", left-1, right, ans);
        }
        if(right > 0 && left < right){
            dfs(curStr+")", left, right-1, ans);
        }
    }
};
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0) return vector<string>();
        vector< vector<string> > dp;
        dp.push_back({""});
        for( int i = 1; i <= n; i++ ){
            vector<string> ans;
            for(int j = 0; j < i; j++){
                auto left = dp[j];
                auto right = dp[i-j-1];
                for( auto && s1 : left){
                    for(auto && s2 : right){
                        ans.push_back("("+s1+")"+s2);
                    }
                }
            }
            dp.push_back(ans);
        }    
        return dp[n];
    }
};