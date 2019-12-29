#include<vector>
using std::vector;

class Solution {
public:
    int maxArea(vector<int>& height) {
        auto it_lo = height.begin();
        auto it_hi = height.end()-1;
        int ans = 0;
        int l = height.size()-1;
        while(it_lo < it_hi){
            int temp = l * std::min(*it_hi,*it_lo);
            --l;
            if(temp > ans)
                ans = temp;
            
            if( *(it_lo) <  *(it_hi))
                ++it_lo;
            else --it_hi;
        }
        return ans;
    }
};