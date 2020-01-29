#include<vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(!nums.size() || nums.size() == 1) return;
        for(auto lo = nums.rbegin()+1; lo != nums.rend(); ++lo){
            if( *lo < *(lo-1) ){
                auto hi = nums.rbegin();
                while( *hi <= *lo ) ++hi;
                swap(*lo, *hi);
                sort(nums.rbegin(),lo,greater<int>());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
