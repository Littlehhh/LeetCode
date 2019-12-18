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
        int  size,i=0,j,k,max=0;
        size = s.size();
        for(j = 0;j<size;j++){
            for(k = i;k<j;k++)
                if(s[k]==s[j]){
                    i = k+1;
                    break;
                }
            if(j-i+1 > max)
                max = j-i+1;
        }
        return max;
    }
};