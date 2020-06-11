#include<vector>
#include<string>
using namespace std;

class Solution {
public: 
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};    
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || board[0].size() == 0) return false;
        if(word.size() == 0) return true;

        int m=board.size(), n=board[0].size();
        
        for( int i=0; i<m;++i ){
            for(int j=0; j<n; ++j){
                if(dfs(i,j,0,word,board))
                    return true;
            }
        }
        return false;
    }

    bool dfs(int row, int col, int w_idx, string & word, vector<vector<char>>& board){
        if( !judgeEdge(row, col, board) || board[row][col]!=word[w_idx]) 
            return false;
        if(w_idx == word.size()-1){
            return true;
        }
        char tmp = board[row][col];
        board[row][col] = '/';
        for( int i=0; i<4; i++){
            int Nr=row+dx[i],Nc=col+dy[i];
            if(dfs(Nr, Nc, w_idx+1,word,board))
                return true;
        }
        board[row][col] = tmp;
        return false;
    }

    bool judgeEdge(int row, int col, vector<vector<char>>& board){
        return row >= 0 && row < board.size() && col >=0 && col < board[0].size();
    }
};