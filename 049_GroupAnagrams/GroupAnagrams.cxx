#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if(strs.size() < 2){
            ans.push_back(strs);
            return ans;
        }  
        unordered_map<string, int> s;
        int count = 0;
        for(auto && str:strs){
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            auto found = s.find(tmp);
            if(found != s.end()){
                ans[s[tmp]].push_back(str);
            }
            else{
                ans.push_back({str});
                s[tmp] = count++;
            }
        }
        return ans;
    }
};