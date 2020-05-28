#include<vector>

using namespace std;

// vector version
class Solution1 {
public:
    // dp or combination 
    int uniquePaths(int m, int n) {
        if(m==0 || n==0) return 0;
        vector<int> ans(m,1);
        while(--n)
            for(int i = 1; i < m; ++i){
                ans[i] = ans[i-1] + ans[i];
            }
        return ans[m-1];
    }
};

// array version
class Solution {
public:
    // dp or combination 
    int uniquePaths(int m, int n) {
        if(m==0 || n==0) return 0;
        // int ans[m] = { [0 ... m] = 1};
        int ans[m];
        fill_n(ans,m,1);
        while(--n)
            for(int i = 1; i < m; ++i){
                ans[i] = ans[i-1] + ans[i];
            }
        return ans[m-1];
    }
};
