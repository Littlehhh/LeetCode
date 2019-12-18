#include<string>
#include<unordered_set>

using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> WordSet;
        size_t ans = 0;
        auto substring_start = s.begin();
        for(auto substring_end = s.begin(); substring_end != s.end(); ++substring_end){           
            while( WordSet.find(*substring_end) != WordSet.end() ){
                WordSet.erase(*substring_start);
                substring_start++;
            }
            WordSet.insert(*substring_end);
            ans = std::max(ans, WordSet.size());
        }
        return ans;
    }
};