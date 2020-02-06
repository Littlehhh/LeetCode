#include<vector>
#include<stack>
#include <chrono> 
#include <iostream> 
using namespace std; 
using namespace std::chrono;


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

int main(){

    int n = 1000000;
    int i = 0;
    auto start = high_resolution_clock::now(); 
    i = 0;
    for( ; i < n ; i++){
        
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 


    start = high_resolution_clock::now(); 
    i = 0;
    while( i < n ){
        i++;
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start); 
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
    return 0; 
}

// Time taken by function: 3373 microseconds
// Time taken by function: 2553 microseconds