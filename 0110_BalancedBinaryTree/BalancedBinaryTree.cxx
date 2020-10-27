#include<cstddef>
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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return  abs(depth(root->left)-depth(root->right)) < 2 && 
                        isBalanced(root->left) &&
                        isBalanced(root->right);
    }
    int depth(TreeNode* root){
        if(!root) return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        return max(l, r)+1;
    }
};
