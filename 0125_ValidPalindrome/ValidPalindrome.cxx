#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
        for(auto & ch:s){
            if(isalpha(ch) || isdigit(ch))
                ans.push_back(toupper(ch));
        }
        if(ans.size() == 0) return true;
        int lo=0,hi=ans.size()-1;
        while(lo<hi && ans[lo]==ans[hi]){
            lo++;hi--;
        }
        return lo>=hi;
    }
};