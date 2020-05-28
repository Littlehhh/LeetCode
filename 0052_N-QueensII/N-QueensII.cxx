class Solution {
public:
    int sum = 0;
    int finishline = 1;
    int totalNQueens(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 0;
        finishline = (finishline << n) - 1;
        backtrace(0, 0, 0);
        return sum;
    }
    void backtrace(long row, long ls, long rs)
    {
        if (row != finishline) // 开始新行
        {
            long position = finishline & ~(row | ls | rs);
            while(position) // 若行间无位可放...
            {
                long pointline = position & -position;
                position -= pointline;
                backtrace(row + pointline, (ls + pointline) << 1, (rs + pointline) >> 1);
            }
        }
        else
        {
            sum++;
        }
    }
};