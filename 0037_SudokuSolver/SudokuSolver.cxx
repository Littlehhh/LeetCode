#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.size() !=9 || board[0].size() != 9 ) return;
        // init state
        unsigned int map[9] = {0};
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                int key = board[i][j]-'1';
                if(key >= 0 && key <= 8 ){
                    int index = (1<<i)     // 行号
                            | (1<<(j+9))    //列号
                            | (1<<(j/3 + i/3*3 + 18));  // 子数独区域序号
                    map[key] |= index;
                }
            }
        }
        
        backtrace(board, map, 0);
    }
    bool backtrace(vector<vector<char>>& board, unsigned int map[], int pos){
        int row = pos / 9;
        int col = pos % 9;
        
        if (pos > 80) return true;

        if (board[row][col] != '.') {
            return backtrace(board, map, pos+1);
        }
        for(int key = 0; key < 9; ++key){
            unsigned int check = (1<<row)     // 行号
                            | (1<<(col+9))    //列号
                            | (1<<(col/3 + row/3*3 + 18));  // 子数独区域序号
            if( (map[key] & check) == 0){
                map[key] |= check;
                board[row][col] = key + '1';
                if(backtrace(board, map, pos+1)) return true;
                else{
                    board[row][col] = '.';
                    map[key] ^= check;
                }
            }
        }
        return false;
    }
};
int main(int argc, char **argv){
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    Solution s = Solution();
    s.solveSudoku(board);
    for(auto && row:board){
        for(auto && col:row){
            cout << col << " ";
        }
        cout << endl;
    }
}