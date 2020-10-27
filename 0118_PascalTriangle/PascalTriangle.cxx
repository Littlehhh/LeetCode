#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows <= 0) return {};
        vector<vector<int>> ans(numRows);
        
        ans[0].emplace_back(1);
        // print(ans);
        for(int i=1; i < numRows; ++i){
            ans[i].emplace_back(1);
            for(int j=1; j < i; ++j ){
                ans[i].emplace_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            ans[i].emplace_back(1);
            // print(ans);
        }
        return ans;
    }
    void print(vector<vector<int>> & ans ){
        for(auto && a:ans){
            for(auto && n:a){
                cout << n << " ";
            }
            cout << endl;
        }
    }
};