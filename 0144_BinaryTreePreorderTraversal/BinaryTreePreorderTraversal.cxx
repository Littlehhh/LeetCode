/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return ans;
        stack<TreeNode *> s;
        s.push(root);
    
        while( !s.empty() ){
            auto cur = s.top();
            s.pop();

            if(!cur) continue;
            ans.push_back(cur->val);
            s.push(cur->right);
            s.push(cur->left);
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> ans;
//     vector<int> preorderTraversal(TreeNode* root) {
//         real_preorderTraversal(root);
//         return ans;
//     }
//     void real_preorderTraversal(TreeNode* root) {
//         if(!root) return;
//         preorderTraversal(root->left);
//         preorderTraversal(root->right);
//     }
// };