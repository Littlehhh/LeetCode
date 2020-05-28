#include<iostream>
#include<vector>

using namespace std;

static const auto io_sync_off = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        
        int lo=0;
        int hi= matrix.size();
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(matrix[mid][0] == target)
                return true;
            else if(matrix[mid][0] < target) lo = mid+1;
            else hi = mid;
        }
        if(lo==0) return false;
        
        return binarySearch(matrix[lo-1], target);
        

    }

    bool binarySearch(vector<int> & nums, int target){
        int lo=0;
        int hi= nums.size();
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] == target)
                return true;
            else if(nums[mid] < target) lo = mid+1;
            else hi = mid;
        }
        return false;
    }
};