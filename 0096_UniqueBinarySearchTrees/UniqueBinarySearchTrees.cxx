#include<vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int numTrees(int n) {
        // long long C = 1;

        // for (int i = 1; i <= n; ++i) {
        //     C = C * 2 * (2 * i - 1) / (i + 1);
        // }
        // return (int)C;
        return (int)catalan(n);
    }


    long catalan(int n)
    {
        if(0 == n || 0 == 1)
        {
            return 1;
        }
    
        return (4 * n - 2) * catalan(n - 1) / (n + 1);
    }

    vector<TreeNode*> ans;
    
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return ans;
        vector<int> vis(n+1, 0);
        
        for(int i = 1; i < vis.size(); ++i){
            TreeNode * root = new TreeNode(i);
            vis[i] = 1;
            generateTrees(n-1, root, vis, root);
            vis[i] = 0;
        }
        return ans;
    }
    void generateTrees(int res, TreeNode* cur, vector<int> &vis, TreeNode* root){
        if(res == 0) {
            ans.push_back(root);
        }
        for(int i = 1; i < vis.size() && vis[i] == 0; ++i){
            vis[i] = 1;
            if(i > cur->val){
                cur->right = new TreeNode(i);
                generateTrees(res-1, cur->right, vis, root);
                
            } 
            else{
                cur->left = new TreeNode(i);
                generateTrees(res-1, cur->left, vis, root);
            } 
            vis[i] = 0;
        }
    }

};


