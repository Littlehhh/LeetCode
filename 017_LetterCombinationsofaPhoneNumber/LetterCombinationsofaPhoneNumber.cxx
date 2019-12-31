#include<vector>
#include<string>
#include<deque>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        deque<string> ans;
        if(digits.size() == 0) return vector<string>();
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
        return vector<string>(ans.begin(), ans.end()) ;
    }
};