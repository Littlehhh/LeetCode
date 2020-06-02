#include<vector>
#include<queue>

using namespace std;

class Solution1 {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        priority_queue<int> heap;   //大根堆
        for ( auto x : arr){
            heap.push(x);
            if (heap.size() > k) heap.pop();
        }
        while (heap.size()) res.push_back(heap.top()), heap.pop();
        return res;
    }
};

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> counter(10001, 0);
        vector<int> ans;
        for ( auto x : arr){
            counter[x]++;
        }
        for( int i = 0; i < 10000 && k; ++i){
            int count = counter[i];
            if(count !=0)
            for(int j = 0; j < count && k; ++j){
                ans.push_back(i);k--;
            }
        }
        return ans;
    }
};