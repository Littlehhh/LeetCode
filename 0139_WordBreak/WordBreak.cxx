#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_set<char> checkdict;
        for(auto & word:wordDict){
            for(auto & ch:word){
                checkdict.insert(ch);
            }
        }
        for(auto & ch:s){
            if(!checkdict.count(ch)) return false;
        }
        unordered_map<string, bool> memo;
        return wordBreak(s, dict, memo);
    }
    bool wordBreak( string s, 
                    unordered_set<string> &dict, 
                    unordered_map<string, bool> &memo){
        auto found = memo.find(s);
        if( found != memo.end()){
            return found->second;
        }
        for( int i=1; i<=s.size(); ++i){
            if(dict.count(s.substr(0,i))){
                if(i == s.size()) return true;
                string subStr = s.substr(i);
                if(wordBreak(subStr, dict, memo)){
                    return true;
                } 
                else{
                    memo[subStr]=false;
                }
            }
        }
        memo[s]=false;
        return false;
    }
    
};