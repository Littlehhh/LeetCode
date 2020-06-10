#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans(T.size());
        // record the index
        stack<int> s;
        for(int i=0; i<T.size(); ++i){
            while(!s.empty() && T[i] > T[s.top()]){
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};