class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> check;
        unordered_map<int, int> cnt;

        for(auto n:arr){
            cnt[n]++;
        }
        for(auto c:cnt){
            if(check.count(c.second)){
                return false;
            }
            else{
                check.insert(c.second);
            }

        }
        return true;

    }
};

