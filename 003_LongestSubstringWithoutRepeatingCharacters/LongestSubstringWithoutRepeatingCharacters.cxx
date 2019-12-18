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