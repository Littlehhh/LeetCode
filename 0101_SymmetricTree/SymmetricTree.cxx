#include<cstddef>
#include<queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
    bool isSymmetric(TreeNode* root) {
        // driver fun
        if( !root ) return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode* left, TreeNode* right){
        if( !left && !right ) return true;
        if( !left || !right ) return false;
        
        return left->val == right->val && 
        isSymmetric(left->left, right->right) &&
        isSymmetric(left->right, right->left);
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        queue <TreeNode*> q;
        q.push(left); q.push(right);
        while (!q.empty()) {
            left = q.front(); q.pop();
            right = q.front(); q.pop();
            if (!left && !right) continue;
            if ((!left || !right) || (left->val != right->val)) return false;

            q.push(left->left); 
            q.push(right->right);

            q.push(left->right); 
            q.push(right->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
};
