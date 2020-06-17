#include<vector>
#include<iostream>

using namespace std;

static const auto io_sync_off = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
    
}();

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int ans = INT_MIN;
        int max_idx=0;
        for(int i=1; i<A.size(); ++i){
            ans = max(ans, A[max_idx]+A[i]+max_idx-i);
            if(A[i]+i-max_idx >= A[max_idx])
                max_idx=i;
        }
        return ans;
    }
};