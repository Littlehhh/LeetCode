#include<string>
#include<unordered_set>

using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> WordSet;
        size_t ans = 0;
        auto substring_start = s.begin();
        // range-based for way
        for(auto && character: s){           
            while( WordSet.find(character) != WordSet.end() ){
                WordSet.erase(*substring_start);
                substring_start++;
            }
            WordSet.insert(character);
            ans = std::max(ans, WordSet.size());
        }
        return ans;
    }
};


// ignore words just concern about the index version 
class Solution {
public:  
   int lengthOfLongestSubstring(string s) {
        std::size_t size,begin=0,end,repeated,max=0;
        size = s.size();
        for(end = 0;end<size;end++){
            for(repeated = begin;repeated<end;repeated++)
                if(s[repeated]==s[end]){
                    begin = repeated+1;
                    break;
                }
            max = std::max(max, end-begin+1);
        }
        return max;
    }
};