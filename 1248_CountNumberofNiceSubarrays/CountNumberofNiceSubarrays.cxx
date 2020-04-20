#include<vector>
#include<unordered_map>
using namespace std;

class Solution1 {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr(nums.size()+1, 0);
        for(int i=0; i<nums.size(); ++i) 
            arr[i+1] = arr[i] + (nums[i]&1);
        unordered_map<int,int> h;
        int ans = 0;
        for(auto x:arr) {
            ans += h[x-k];
            h[x] ++;
        }
        return ans;
    }
};


class Solution2 {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int odd[n + 2], ans = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] & 1) odd[++cnt] = i;
        }
        odd[0] = -1, odd[++cnt] = n;
        for (int i = 1; i + k <= cnt; ++i) {
            ans += (odd[i] - odd[i - 1]) * (odd[i + k] - odd[i + k - 1]); 
        }
        return ans;
    }
};
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int arr[50005];
        memset(arr, 0, sizeof(arr));
        int n = nums.size(), res = 0, cur = 0;
        arr[0] = 1;
        for (int i = 0; i < n; ++i) {
            cur += nums[i] % 2;
            if (cur - k >= 0) {
                res += arr[cur - k];
            }
            ++arr[cur];
        }
        return res;
    }
};
