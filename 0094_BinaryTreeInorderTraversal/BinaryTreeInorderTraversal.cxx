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
    vector<int> ans;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return ans;
        Traversal(root);
        return ans;
    }
    void Traversal(TreeNode * root){
        if(root == nullptr) return ;
        if(root->left != nullptr) Traversal(root->left);
        ans.push_back(root->val);
        if(root->right != nullptr) Traversal(root->right);
    }
};


