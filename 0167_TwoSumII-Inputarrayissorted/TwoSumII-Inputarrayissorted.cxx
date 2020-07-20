#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> dict;
        for(int i=0; i<numbers.size(); ++i){
            auto found = dict.find(target-numbers[i]);
            if(found != dict.end()){
                return {found->second, i+1};
            }
            else{
                dict[numbers[i]]=i+1;
            }
        }
        return {};
    }
};
