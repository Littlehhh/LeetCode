#include<cstddef>
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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int l_height = maxDepth(root->left);
        int r_height = maxDepth(root->right);
        return max(l_height, r_height)+1;
    }
};