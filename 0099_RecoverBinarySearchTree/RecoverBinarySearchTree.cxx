#include<vector>
#include<stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode* > s;
        TreeNode* x = nullptr;
        TreeNode* y = nullptr;
        TreeNode* pred = nullptr;
        while(!s.empty() || root){
            while( root ){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if( pred && root->val < pred->val){
                y = root;
                if(!x){
                    x = pred;
                }
                else break;
            }
            pred = root;
            root = root->right;
        }
        swap(x->val, y->val);

    }
};