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


using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t m = nums1.size(), n = nums2.size();
        if(m > n) return findMedianSortedArrays(nums2, nums1);
        size_t first = 0, last = m; //二分较短的那个
        // 分割在右边
        size_t median = (m+n+1)/2;
        //size_t median_right = (m+n+2)/2;
        while(first < last){
            size_t mid = first + (last - first) / 2;
            if( max(nums1[mid - 1], nums2[median - mid - 1]) > 
                min(nums1[mid], nums2[median - mid])){
                
            }
            if(mid != 0 && nums1[mid - 1] > nums2[median - mid]  )
                last = mid;
            else
            if(nums1[mid] < nums2[median - mid] && mid != m)
                first = mid+1;
            else{
                size_t MaxLeft, MinRight;
                if(mid == 0 || mid == m){
                    MaxLeft = nums2[median - mid - 1];
                    MinRight = nums2[median - mid];
                }
                else{
                    MaxLeft = std::max(nums1[mid - 1], nums2[median - mid - 1]);
                    MinRight = std::min(nums1[mid], nums2[median - mid]);
                }

                if((m+n) % 2 == 1) return MaxLeft;
                else return (MaxLeft+MinRight) / 2.0;
            }
        }
        
        return 0.0;
        
    }
};

int main(int argc, char **argv){
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    Solution s = Solution();
    s.findMedianSortedArrays(nums1, nums2);
}