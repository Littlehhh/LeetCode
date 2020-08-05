#include<unordered_map>
#include<algorithm>

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
    unordered_map <TreeNode*, int> f, g;

    void dfs(TreeNode* r) {
        if (!r) {
            return;
        }
        dfs(r->left);
        dfs(r->right);
        f[r] = r->val + g[r->left] + g[r->right];
        g[r] = max(f[r->left], g[r->left]) + max(f[r->right], g[r->right]);
    }

    int rob(TreeNode* r) {
        dfs(r);
        return max(f[r], g[r]);
    }
};
