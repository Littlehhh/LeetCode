#include<string>
#include<vector>
using namespace std;

class Trie {
private:
    Trie * next[26] = { nullptr };
public:
    /** Initialize your data structure here. */
    Trie() {}
    /** Inserts a word into the trie. */
    bool insert(string word) {
        Trie * root = this;
        bool is_new = false;
        for(auto && w : word){
            int index = w-'a';
            if(root->next[index] == nullptr){
                root->next[index] = new Trie();
                is_new = true;
            }
            root = root->next[index];
        }
        return is_new;
    }

};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie * tree = new Trie();
        int count = 0;
        sort(words.begin(), words.end(),
        [](string &a, string &b){return a.size()>b.size();}
        );
        for(auto && w:words){
            reverse(w.begin(), w.end());
            if( tree->insert( w ) )
            count +=  w.size()+1; 
        }
        return count;
    }
};

