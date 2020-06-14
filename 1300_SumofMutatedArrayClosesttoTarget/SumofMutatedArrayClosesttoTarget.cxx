#include<vector>

using namespace std;

class Solution1 {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> prefix(n + 1);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + arr[i - 1];
        }

        int r = *arr.rbegin();
        int ans = 0, diff = target;
        for (int i = 1; i <= r; ++i) {
            auto iter = lower_bound(arr.begin(), arr.end(), i);
            int cur = prefix[iter - arr.begin()] + (arr.end() - iter) * i;
            if (abs(cur - target) < diff) {
                ans = i;
                diff = abs(cur - target);
            }
        }
        return ans;
    }
};


class Solution {
public:
    int sumFunc(vector<int>& arr, int threshold) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= threshold) {
                sum += arr[i];
            } else {
                sum += threshold;
            }
        }
        return sum;
    }
    int findBestValue(vector<int>& arr, int target) {
        int left = 1;
        int right = *max_element(arr.begin(), arr.end());  // 二分法上下限分别是0和max(arr)
        while (left < right) {
            int mid = left + (right - left) / 2;
            int sum = sumFunc(arr, mid);
            if (sum < target) {
                left = mid + 1;
            } else {
                right = mid;
            } 
        }
        int sum1 = sumFunc(arr, left - 1);
        int sum2 = sumFunc(arr, left);
        if (sum2 - target >= target - sum1) {
            return left - 1;
        } else {
            return left;
        }
    }
};