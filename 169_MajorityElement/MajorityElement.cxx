#include<vector>
#include<unordered_map>

using namespace std;
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> table;
        for(auto && num:nums){
            table[num]++;
        }
        int max = INT_MIN;
        int max_index = -1;
        for(auto && item:table){
            if(item.second > max){
                max = item.second;
                max_index = item.first;
            }
        }
        return max_index;
    }
};

// Moore voting
class Solution {
public:
    int majorityElement(vector<int>& nums) {    
        int count=0,candidate;
        for(int n:nums)
        {
            if(count==0)        candidate=n;

            if(n==candidate)    count++;
            else                count--;
        }
        return candidate;
    }
};
