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
        return maxDepth(root) == -1 ? false : true;
    }
    int maxDepth(TreeNode* root){
        if(!root) return 0;
        int left = maxDepth(root->left);
        if(left == -1) return -1;
        int right = maxDepth(root->right);
        if(right == -1) return -1; 
        return std::abs(left-right) > 1 ? -1 : std::max(left,right)+1;
    }
};