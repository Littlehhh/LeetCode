#include<unordered_map>
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
    unordered_map<int, int> index;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() != inorder.size()) return nullptr;
        for(int i=0; i < inorder.size(); ++i){
            index[inorder[i]] = i;
        }
        TreeNode * root = buildTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
        return root;
    }
    TreeNode * buildTree(vector<int>& preorder, vector<int>& inorder, int preL, int preR, int inL, int inR){
        if(preL > preR) return nullptr;
        TreeNode * root = new TreeNode(preorder[preL]);
        int inRootIdx = index[preorder[preL]];
        int leftSubTreeLen = inRootIdx - inL;
        // preorder left subtree is same len with inorder subtree len
        root->left = 
        buildTree(preorder, inorder, preL+1, preL+leftSubTreeLen, inL, inRootIdx-1);
        root->right = 
        buildTree(preorder, inorder, preL+leftSubTreeLen+1, preR,inRootIdx+1, inR);
        return root;
    }
};
