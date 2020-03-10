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
    int ans;
    int depth(TreeNode* root){
        if (root == nullptr) return 0; 
        int l_height = depth(root->left); 
        int r_height = depth(root->right); 
        ans = max(ans, l_height + r_height + 1); 
        return max(r_height, l_height) + 1; 
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }
};