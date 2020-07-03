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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);  
    }
    TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
        if(r == l) return new TreeNode(nums[r]); 
        if(r < l) return nullptr;
        int mid = l + (r - l + 1) / 2; // right mid
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, l, mid-1);
        root->right = sortedArrayToBST(nums, mid+1, r);
        return root;
    } 
};