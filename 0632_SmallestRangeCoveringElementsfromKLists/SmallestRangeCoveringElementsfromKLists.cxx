#include<vector>
#include<unordered_map>
#include<climits>
#include<queue>

using namespace std;

class Solution1 {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> indices;
        int xMin = INT_MAX, xMax = INT_MIN;
        for (int i = 0; i < n; ++i) {
            for (const int& x: nums[i]) {
                indices[x].push_back(i);
                xMin = min(xMin, x);
                xMax = max(xMax, x);
            }
        }

        vector<int> freq(n);
        int inside = 0;
        int left = xMin, right = xMin - 1;
        int bestLeft = xMin, bestRight = xMax;

        while (right < xMax) {
            ++right;
            if (indices.count(right)) {
                for (const int& x: indices[right]) {
                    ++freq[x];
                    if (freq[x] == 1) {
                        ++inside;
                    }
                }
                while (inside == n) {
                    if (right - left < bestRight - bestLeft) {
                        bestLeft = left;
                        bestRight = right;
                    }
                    if (indices.count(left)) {
                        for (const int& x: indices[left]) {
                            --freq[x];
                            if (freq[x] == 0) {
                                --inside;
                            }
                        }
                    }
                    ++left;
                }
            }
        }

        return {bestLeft, bestRight};
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int rangeLeft = 0, rangeRight = INT_MAX;
        int size = nums.size();
        vector<int> next(size);
        
        auto cmp = [&](const int& u, const int& v) {
            return nums[u][next[u]] > nums[v][next[v]];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int minValue = 0, maxValue = INT_MIN;
        for (int i = 0; i < size; ++i) {
            pq.emplace(i);
            maxValue = max(maxValue, nums[i][0]);
        }

        while (true) {
            int row = pq.top();
            pq.pop();
            minValue = nums[row][next[row]];
            if (maxValue - minValue < rangeRight - rangeLeft) {
                rangeLeft = minValue;
                rangeRight = maxValue;
            }
            if (next[row] == nums[row].size() - 1) {
                break;
            }
            ++next[row];
            maxValue = max(maxValue, nums[row][next[row]]);
            pq.emplace(row);
        }

        return {rangeLeft, rangeRight};
    }
};

