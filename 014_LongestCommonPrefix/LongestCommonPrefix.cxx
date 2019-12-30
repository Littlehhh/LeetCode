#include<string>
#include<set>
#include<vector>
using namespace std;


class Solution1 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        set<string> sorted_strs(strs.begin(), strs.end());
        auto lo = sorted_strs.begin();
        auto hi = --sorted_strs.end();
        
        string ans("");
        for( int i = 0; i< (*lo).size(); i++){
            if((*lo)[i] == (*hi)[i])
                ans.push_back((*lo)[i]);
            else break;
        }
        return ans;
    }
};
class Solution2 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0)
            return "";
        auto lo = max_element(strs.begin(), strs.end());
        auto hi = min_element(strs.begin(), strs.end());
        auto pair = mismatch(lo->begin(), lo->end(), hi->begin());
        return string(lo->begin(), pair.first);
    }  
};


class Trie {
public:
    char next_ch = '-';
    Trie * next = nullptr;

    /** Initialize your data structure here. */
    Trie() {}
    void init(string str){
        Trie * root = this;
        for(auto && s : str){
            root->next_ch = s;
            root->next = new Trie();
            root = root->next;
        }
    }
    void CommonPrefix(string str){
        Trie * root = this;    
        for(auto && s : str){
            if(root->next_ch=='-') break;
            if(root->next_ch != s){
                root->next_ch = '-';
                break;
            }
            else{
                root = root->next;
            }      
        }
        root->next_ch = '-';
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0 ) return "";
        if(strs.size() == 1) return strs[0];
        Trie * root = new Trie();
        root->init(strs[0]);
        for(auto && str : strs){
            if( str.size() == 0) return "";
            root->CommonPrefix(str);
        }
        string ans;
        while(root->next_ch != '-'){
            ans.push_back(root->next_ch);
            root = root->next;
        }
        return ans;
    }  
};