#include<vector>

using namespace std;

class Solution {
public:
    int m,n;
    int dx[8] = {1,-1,0,0,1,-1,1,-1};
    int dy[8] = {0,0,1,-1,1,-1,-1,1};
    enum STATUS{DEAD=0,LIVE=1,REVIVAL=2,PRELIVE=3};
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size() == 0 || board[0].size() == 0) return;
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                int count = countLive(i,j,board);
                if(board[i][j] == DEAD || board[i][j] == REVIVAL){
                    if(count == 3){
                        board[i][j] = REVIVAL;
                    }
                }
                else if(board[i][j] == LIVE || board[i][j] == PRELIVE){
                    if(count < 2){
                        board[i][j] = PRELIVE;
                    }
                    else if(count > 3){
                        board[i][j] = PRELIVE;
                    }
                }
                
            }
        }
        for(int i = 0; i < board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                if(board[i][j] == REVIVAL){
                    board[i][j] = LIVE;
                }
                else if(board[i][j] == PRELIVE){
                    board[i][j] = DEAD;
                }
            }
        }
        return;
    }
    int countLive(int row, int col, vector<vector<int>>& board){
        int count = 0;     
        for(int i=0; i<8; ++i){
            int x = row + dx[i];
            int y = col + dy[i];
            if(judgeEdge(x,y)&&(board[x][y]==LIVE||board[x][y]==PRELIVE))
                count++;
        }
        return count;
    }
    bool judgeEdge(int x, int y){
        if(x<m && x>=0 && y<n && y>=0)
            return true;
        else return false;
    }
};

