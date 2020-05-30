#include<stack>
#include<vector>
#include<climits>


class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int n = heights.size();
        if(n==0) return 0;
        int max_area = 0;
        std::stack<int> s;
        
        int cur_min=INT_MAX;
        for(auto && r_it=heights.rbegin(); r_it!=heights.rend(); ++r_it){
            cur_min = std::min(*r_it, cur_min);
            s.push(cur_min);
        }
        
        for(int i=0; i<n; ++i){
            int min_height = INT_MAX;
            for(int j=i; j<n; ++j){
                min_height = std::min(min_height, heights[j]);
                if(min_height == s.top()) {
                    max_area = std::max((n-i) * min_height, max_area);
                    break;
                }
                max_area = std::max(max_area, min_height * (j-i+1));
            }
            s.pop();
        }
        return max_area;
    }
};