#include<iostream>
#include<vector>
// 二分法查找 复杂度 O(log(m+n))  二分查找value 这个查找 pos
// 长度分别为 m, n 的数组 寻找第 k 个数
// 1 2 4 7 8 9
// 3 4 5 9
// 10 个数 找第 5、6 个数
// 偶数
// 1  3 4 | 5 9 分界 i
// 2  1 2 4 | 7 8 9  分界 j
// 奇数
// 1  3 4 5 | 7 9 分界 i
// 2  1 2 4 | 7 8 9  分界 j

// max(L1, L2) <= min(R1, R2) 成立
// if L1 > R2 last = mid -> {1}[first,last) = {empty} <=> first = last
// if L2 > R1 first = mid -> {1}[first,last) = {full} <=> first = last 
//

static int speedup = [](){
    ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
}();

static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t m = nums1.size(), n = nums2.size();
        cout << m << endl;
        if(m > n) return findMedianSortedArrays(nums2, nums1);
        size_t first = 0, last = m; //二分较短的那个
        size_t median = (m+n+1)/2;
        while(first <= last){
            size_t mid = first + (last - first) / 2;
            size_t remain = median - mid;
            if(mid != 0 && nums1[mid - 1] > nums2[remain]  )
                last = mid;
            else
            if(mid != m && nums1[mid] < nums2[remain-1])
                first = mid+1;
            else{
                size_t MaxLeft, MinRight;
                if(mid == 0){
                    MaxLeft = nums2[remain-1];
                }
                else if(remain == 0){
                    MaxLeft = nums1[mid-1];
                }
                else{
                    MaxLeft = std::max(nums1[mid-1], nums2[remain-1]);
                }
                if(mid == m){
                    MinRight = nums2[remain];
                }
                else
                if(remain == n){
                    MinRight = nums1[mid];
                }
                else{
                    MinRight = std::min(nums1[mid], nums2[remain]);
                }
                

                if((m+n) % 2 == 1) {
                    cout << MaxLeft << endl;
                    return MaxLeft;
                }
                else {
                    cout << (MaxLeft+MinRight) / 2.0 << endl;
                    return (MaxLeft+MinRight) / 2.0;
                }
            }
        }
        cout << "Done";
        return 0.0;
        
    }
};


class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t m = nums1.size(), n = nums2.size();
        cout << m << endl;
        // ensure binary search the shorter one
        if(m > n) return findMedianSortedArrays(nums2, nums1);
        size_t first = 0, last = m;
        size_t k = (m+n+1)/2;
        size_t mid, remain;
        while(first < last){
            mid = first + (last - first) / 2;
            remain = k - mid;
            if(nums1[mid] < nums2[remain-1])
                first = mid+1;
            else 
                last = mid;
        }
        
        mid = first + (last - first) / 2;   
        remain = k - mid;
        int MaxLeft, MinRight;
        MaxLeft = max(mid<=0?    INT_MIN : nums1[mid-1],
                      remain<=0? INT_MIN : nums2[remain-1]);
        if( (m+n)&1) return MaxLeft;
        MinRight = min(mid>=m?    INT_MAX : nums1[mid],
                       remain>=n? INT_MAX : nums2[remain]);
        return (MaxLeft+MinRight) * 0.5;
        
    }
};



int main(int argc, char **argv){
    vector<int> nums1;
    vector<int> nums2 = {1};
    Solution s = Solution();
    s.findMedianSortedArrays(nums1, nums2);
}


