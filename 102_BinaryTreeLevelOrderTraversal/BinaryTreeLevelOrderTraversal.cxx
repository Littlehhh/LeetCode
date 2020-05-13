#include<vector>
#include<queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int size = 0;
        while(!q.empty()){
            size = q.size();
            vector<int> level;
            while(size--){
                TreeNode* cur = q.front();
                q.pop();
                if (!cur) {
                    continue;
                }
                level.push_back(cur->val);
                q.push(cur->left);
                q.push(cur->right);
            }
            if (level.size() != 0) {
                ans.push_back(level);
            }
        }
        return ans;
    }
};