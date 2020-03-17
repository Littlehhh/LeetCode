#include<string>
#include<vector>
#include<unordered_set>
#include<iostream>

static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int sum = 0;
        
        for(auto && word:words){
            unordered_multiset<char> lookup(chars.begin(), chars.end());
            bool can = true;
            for(auto && ch:word){
                auto find = lookup.find(ch);
                if(find != lookup.end()){
                    lookup.erase(find);
                }
                else{
                    can = false;
                    break;
                }
            }
            if(can) sum+=word.size();
        }
        return sum;
    }
};



class Solution1 {
public:
    int countCharacters(vector<string>& words, string chars) {
        int sum = 0;
        sort(chars.begin(), chars.end());
        for(auto && word:words){
            if(word.size() <= chars.size()){
                sort(word.begin(), word.end());
                bool can = true;
                auto word_it = word.begin();
                auto chars_it = chars.begin();
                while(word_it != word.end() && chars_it != chars.end()){
                    if(*word_it == *chars_it){
                        word_it++;chars_it++;
                    }
                    else{
                        chars_it = 
                        lower_bound(chars_it, chars.end(), *word_it);
                        if(chars_it == chars.end()|| *chars_it != *word_it ){
                            can = false;
                            break;
                        } 
                        chars_it++;
                        word_it++;
                    }
                }
                if(can && word_it==word.end()) sum+=word.size();
            }
        }
        return sum;
    }
};