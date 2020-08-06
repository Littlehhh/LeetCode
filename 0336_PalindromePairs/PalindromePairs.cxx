#include<vector>
#include<string>

using namespace std;

class Trie {
public:
    Trie * next[26] = {nullptr};
    int index;
    vector<int> suffixs;
    Trie():index(-1){}
};


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        if(words.size() < 2) return {};
        vector<vector<int>> ans;
        // build tree
        Trie * root = new Trie();
        for(int i=0; i<words.size(); ++i){
            auto s = words[i];
            Trie * cur = root;
            if( is_palindrome(s) )  cur->suffixs.push_back(i);
            for(auto ch=s.rbegin(); ch!=s.rend(); ++ch){
                int index = *ch - 'a';
                if( !cur->next[index] ) cur->next[index] = new Trie();
                cur = cur->next[index];

                if(is_palindrome( string(ch+1, s.rend()) ) ){
                    cur->suffixs.push_back(i);
                }
            }
            cur->index = i;
        }
        
        // search
        for(int i=0; i<words.size(); ++i){
            auto s = words[i];
            Trie * cur = root;
            int j=0;
            // cout << s.size();
            while(j<s.size()){
                if(is_palindrome( s.substr(j) ) && cur->index!=-1)
                    ans.push_back({i, cur->index});
                int index = s[j]-'a';
                if( !cur->next[index] ) break;
                cur = cur->next[index];
                j++;
            } 
            if(j == s.size()){
                for(int k:cur->suffixs){
                    if(k != i){
                        ans.push_back({i, k});
                    }
                }
            }
            
        }
        return ans;
    }

    bool is_palindrome(string s){
        int lo=0, hi=s.size()-1;
        while(lo<hi){
            if(s[lo++] != s[hi--]){
                return false;
            }
        } 
        return true;
    }
}; 
