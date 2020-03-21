#include<vector>
#include<queue>

using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;   
        for ( auto x : nums){
            heap.push(x);
            if (heap.size() > k) heap.pop();
        }
        return heap.top();
    }

};

class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        partial_sort(nums.begin(), nums.begin()+k-1, nums.end());
        return nums[k-1];
    }
};
