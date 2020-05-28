#include<vector>
#include<iostream>

using namespace std;

static const auto io_sync_off = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution1 {
public:
    int minIncrementForUnique(vector<int>& A) {
        vector<int> ans(80000, 0);
        int count = 0;
        for(auto && num:A){
            if(ans[num] == 0){
                ans[num] = 1;
            }
            else{
                count++;
                while(++num < 80000 && ans[num] != 0){
                    count++;
                }
                ans[num] = 1;
            }
        }
        return count;
    }
};
// linear detection && path compress
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        vector<int> pos(40000+A.size(), -1);
        int count = 0;
        for(auto && num:A){
            count += (findPos(pos, num) - num);
        }
        return count;
    }
    int findPos(vector<int> &pos, int num){
        // stack<int> idx;
        // int i = num;
        // while( pos[i] != -1 ){
        //     idx.push(i);i=pos[i]+1;
        // }
        // pos[i] = i;
        // while( !idx.empty() ){
        //     pos[idx.top()] = i;
        //     idx.pop();
        // }
        // return i;
        if(pos[num] == -1){
            pos[num] = num;
            return num;
        }

        int newPos = findPos(pos, pos[num]+1);
        pos[num] = newPos;
        return newPos;
    }
};
