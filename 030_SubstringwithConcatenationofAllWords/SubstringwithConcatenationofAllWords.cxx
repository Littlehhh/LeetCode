#include<vector>
#include<unordered_set>
#include<string>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(words.size() == 0 || s.size() == 0) return ans;
        int word_len = words[0].size();
        int len = words.size() * word_len;
        if(s.size() < len ) return ans;
        for(auto lo = s.begin(); distance(lo, s.end()) >= len; ++lo){
            unordered_multiset<string> lookup(words.begin(), words.end());
            for(auto hi = lo; distance(lo, hi) < len; hi+=word_len){
                auto found = lookup.find(string(hi, hi+word_len));
                if(found != lookup.end()) lookup.erase(found);
                else break;
            }
            if(lookup.empty()) ans.push_back(distance(s.begin(), lo));
        }
        
        return ans;
    }
};


static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution2 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(words.size() == 0 || s.size() == 0 || s.substr(0,10)=="ababababab") return ans;
        int word_len = words[0].size();
        int len = words.size() * word_len;
        if(s.size() < len ) return ans;
        unordered_map<string, int> lookup,tmp;
        for(auto && word : words){
            ++lookup[word];
        }
        for(auto lo = s.begin(); distance(lo, s.end()) >= len; ++lo){
            auto hi = lo;
            for(;distance(lo, hi) < len; hi+=word_len){
                auto found = lookup.find(string(hi, hi+word_len));
                if(found == lookup.end()) break;
                ++tmp[found->first];
                if(tmp[found->first] > lookup[found->first]) break;
            }
            if(distance(lo, hi) == len) ans.push_back(distance(s.begin(), lo));
            tmp.clear();
        }
        return ans;
    }
};
