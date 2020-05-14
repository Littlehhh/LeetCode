#include<vector>
#include<deque>

using namespace std;

class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() * k == 0) return vector<int>{};
        if(k == 0) return nums;
        deque<int> index;
        vector<int> ans;
        // init deque
        for(int i=0; i<k; ++i){
            if(index.empty()){
                index.push_back(i);
            }
            else{
                while(!index.empty() && nums[i] > nums[index.back()]){
                    index.pop_back();
                }
                index.push_back(i);
            }
        }
        ans.push_back(nums[index.front()]);

        // slide
        for(int i=k; i < nums.size(); ++i){
            //clean front
            if( index.front() == i-k) index.pop_front();
            
            // keep max_index front
            while(!index.empty() && nums[i] > nums[index.back()]){
                    index.pop_back();
            }
            index.push_back(i);
            ans.push_back(nums[index.front()]);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        vector<int> left(n, 0), right(n, 0);
        int maxNum;
        for(int i = 0; i < n; i ++){
            if(i % k == 0){
                maxNum = nums[i];
            }
            maxNum = max(maxNum, nums[i]);
            left[i] = maxNum;
        }
        maxNum = nums[n - 1];
        for(int i = n - 1; i >= 0; i --){
            if(i % k == k - 1){
                maxNum = nums[i];
            }
            maxNum = max(maxNum, nums[i]);
            right[i] = maxNum;
        }
        for(int i = 0; i <= n - k; i ++){
            ans.push_back(max(right[i], left[i + k - 1]));
        }
        return ans;
    }
};


