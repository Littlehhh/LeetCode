#include<vector>

using namespace std;

class TreeAncestor {
public:
    vector<vector<int>> dp;
    int len;
    TreeAncestor(int n, vector<int>& parent):len(n),dp(n, vector<int>(20, -1)){
        for(int i=0; i<n; ++i){
            dp[i][0] = parent[i];
        }
        for(int j=1; j<20; ++j){
            for(int i=0; i<n; ++i){
                if(dp[i][j-1] != -1){
                    dp[i][j]=dp[dp[i][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(node < 0 || node >= len) return -1;
        if(k==0) return node;

        for( int i=19; i>=0; --i){
            if( k & (1<<i) )
                node = dp[node][i];
                if(node == -1) break;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */