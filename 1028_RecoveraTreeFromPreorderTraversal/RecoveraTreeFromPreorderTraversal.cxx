#include<string>
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
    TreeNode* recoverFromPreorder(string S) {
        if(S.size() == 0) return nullptr;
        int rootLen = getNumEndIdx(S);
        TreeNode * root = new TreeNode(stoi(S.substr(0,rootLen)));
        if(rootLen == S.size()) return root;
        auto Idx = findMid(S, rootLen);
        if(Idx.first == S.size()){
            root->left=recoverFromPreorder(S.substr(Idx.second+rootLen));
            root->right=nullptr;
        }
        else{
            int lenL = Idx.first-Idx.second-rootLen-Idx.second;
            string subStringL = S.substr(Idx.second+rootLen, lenL);
            root->left = recoverFromPreorder(subStringL);
            string subStringR = S.substr(Idx.first);
            root->right = recoverFromPreorder(subStringR);
        }
        return root;
    }

    int getNumEndIdx(string &S){
        int count=0;
        for(int i=0; i<S.size(); ++i){
            if(isdigit(S[i])){
                count++;
            }
            else break;
        }
        return count;
    }

    pair<int, int> findMid(string &S, int startIdx){
        // find level len
        int level=0;
        while(S[startIdx++] == '-'){
            level++;
        }
        int count=0;
        int i = startIdx;
        for(; i<S.size(); ++i){
            if(S[i] == '-'){
                count++;
            }
            else{
                if(count==level) break;
                count=0;
            }
        }
        return {i, level};
    }
};