#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3) return 0;
        int ans = 0;
        int i=0;
        stack<int> st;
        while ( i < height.size() ) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty())
                    break;
                int distance = i - st.top() - 1;
                int bounded_height = min(height[i], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(i++);
        }
        return ans;
    }
};