#include<string>
using namespace std;

class Trie {
private:
    bool is_string = false;
    Trie * next[26] = { nullptr };
public:
    /** Initialize your data structure here. */
    Trie() {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie * root = this;
        for(auto && w : word){
            int index = w-'a';
            if(root->next[index] == nullptr)
                root->next[index] = new Trie();
            root = root->next[index];
        }
        root->is_string=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie * root = this;
        for(auto && w : word){
            int index = w-'a';
            if(root->next[index] == nullptr)
                return false;
            root = root->next[index];
        }
        return root->is_string;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie * root = this;
        for(auto && w : prefix){
            int index = w-'a';
            if(root->next[index] == nullptr)
                return false;
            root = root->next[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */