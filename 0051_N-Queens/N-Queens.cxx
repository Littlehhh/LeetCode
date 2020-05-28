#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<string> tmp;
    int n;
    int finishline = 1;
    vector<vector<string>> solveNQueens(int n) {
        if(n==0 || n == 2) return ans;
        if(n==1) return {{"Q"}};
        this->n = n;
        finishline = (finishline << n) - 1;
        backtrace(0, 0, 0);
        return ans;
    }

    string generate_position(long position){
        string pos;
        for(int i = 0; i < this->n; ++i){
            if( position & 1){
                pos.push_back('Q');
            }
            else{
                pos.push_back('.');
            }
            position >>= 1;
        }
        return pos;
    }

    void backtrace(long row, long ls, long rs)
    {
        if (row != finishline) // 开始新行
        {
            long position = finishline & ~(row | ls | rs);
            while(position) // 若行间无位可放...
            {
                long pointline = position & -position;
                tmp.push_back(generate_position(pointline));
                position -= pointline;
                backtrace(row + pointline, (ls + pointline) << 1, (rs + pointline) >> 1);
                tmp.pop_back();
            }
        }
        else
        {
            ans.push_back(tmp);
        }
    }
};