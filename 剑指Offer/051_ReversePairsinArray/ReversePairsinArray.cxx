#include<iostream>
#include<vector>

using namespace std;

static auto io_sync_off=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> t;
    int merge_sort(vector<int>&nums, int l, int r){
        if(l >= r) return 0;
        int mid = l + r >> 1;
        int res = merge_sort(nums, l, mid) + merge_sort(nums, mid+1, r);
        int i = l, j = mid+1, k=l;
        while(i <= mid && j <= r){
            if(nums[i] <= nums[j]){
                t[k++] = nums[i++];
            } else {
                res += mid - i + 1;
                t[k++] = nums[j++];
            }
        }
        while(i <= mid) t[k++] = nums[i++];
        while(j <= r) t[k++] = nums[j++];
        for(int i=l;i<=r;i++) nums[i] = t[i];
        return res;
    }
    int reversePairs(vector<int>& nums) {
        t.resize(nums.size(),0);
        return merge_sort(nums, 0, nums.size()-1);
    }
};

class Solution1 {
public:
    int n;
    vector<int> c;
    void add(int x, int y){
        for(;x<=n;x+=x&-x) c[x] += y;
    }
    int ask(int x){
        int res = 0;
        for(;x;x-=x&-x) res+= c[x];
        return res;
    }
    int reversePairs(vector<int>& nums) {
        vector<int> alls = nums;
        c.resize(nums.size() + 1, 0);
        n = nums.size();
        sort(alls.begin(),alls.end());
        int res = 0;
        for(auto x : nums){
            int pos = lower_bound(alls.begin(),alls.end(), x) - alls.begin() + 1;
            res += ask(n) - ask(pos);
            add(pos, 1);
        }
        return res;
    }
};

