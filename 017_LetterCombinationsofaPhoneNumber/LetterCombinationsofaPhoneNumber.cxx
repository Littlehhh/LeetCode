#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) return ans;
        vector<string> se={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(auto && num : digits){
            string letter = se[num - '0'];
            if(ans.size() == 0){
                for(auto && l : letter){
                    ans.push_back(string(1,l));
                }
            }
            else{
                int curSize = ans.size();
                for(int i = 0; i < curSize; ++i){
                    for(auto && l : letter){
                        ans.push_back(string(ans[i]+string(1,l)));
                    }
                }
                ans.erase(ans.begin(), ans.begin()+curSize);
            }
        }
        return ans;
    }
};