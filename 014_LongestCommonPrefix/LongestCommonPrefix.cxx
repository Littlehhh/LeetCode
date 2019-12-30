#include<string>
#include<set>
#include<vector>
using namespace std;


class Solution1 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        set<string> sorted_strs(strs.begin(), strs.end());
        auto lo = sorted_strs.begin();
        auto hi = --sorted_strs.end();
        
        string ans("");
        for( int i = 0; i< (*lo).size(); i++){
            if((*lo)[i] == (*hi)[i])
                ans.push_back((*lo)[i]);
            else break;
        }
        return ans;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0)
            return "";
        auto lo = max_element(strs.begin(), strs.end());
        auto hi = min_element(strs.begin(), strs.end());
        auto pair = mismatch(lo->begin(), lo->end(), hi->begin());
        return string(lo->begin(), pair.first);
    }  
};
