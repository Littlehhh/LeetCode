
#include<unordered_set>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution1 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int longestStreak = 0;
        for (auto && num : num_set) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;
                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;           
    }
};


class Solution {
public:
    unordered_map<int,int> a;
    int find(int x){
        return a.count(x)?a[x]=find(a[x]):x;
    }
    int longestConsecutive(vector<int>& nums) {
        for(auto i:nums)
            a[i]=i+1;
        int ans=0;
        for(auto i:nums){
            int y=find(i+1);
            ans=max(ans,y-i);
        }
        return ans;
    }
};
