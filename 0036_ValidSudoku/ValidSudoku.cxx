#include<vector>
#include<array>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size() == 0) 
            return false;
        unsigned int map[9] = {0};
        for(int y=0; y<9; y++){
            for(int x=0; x<9; x++){
                int key = board[y][x] - '1';
                if(key >= 0 && key <= 8) {
                    int index = (1<<x)     //Value:位置编码，最低9位存放列号
                            | (1<<(y+9))    //中间9位存放行号
                            | (1<<(x/3 + y/3*3 + 18));  // 子数独区域序号
                    int old = map[key];
                    if((old & index) == 0) //无重复，则按位或，加入位置集合
                        map[key] = old | index;
                    else                    //有重复
                        return false;
                }
            }
        }
        return true;
    }
};