#include<vector>

using namespace std;

class Solution {
public:
    using VecPair = vector<pair<int, int>>;
    using VecPairIt = vector<pair<int, int>>::iterator;
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> v;
        int n = nums.size();
        v.reserve(n);
        for (int i = 0; i < n; ++i) {
            v.emplace_back(nums[i], i);
        }
        
        vector<int> res(n);
        merge_sort(v.begin(), v.end(), res);
        return res;
    }
    
    void merge_sort(VecPairIt l, VecPairIt r, vector<int>& res) {
        if (r-l <= 1) return;
        auto mid = l + (r-l) / 2;
        merge_sort(l, mid, res); // [l, mid)
        merge_sort(mid, r, res); // [mid, r)
        
        auto i = l;
        auto j = mid;
        while (i < mid || j < r) {
            if (j == r || (i < mid && i->first <= j ->first)) {
                res[i->second] += j - mid;
                ++i;
            } else {
                ++j;
            }
        }

        inplace_merge(l, mid, r);
    }
};