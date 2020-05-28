class Solution {
public:
    int mySqrt(int x) {
        if(x < 0) return -1;
        if(x == 1 || x == 0) return x;
        int lo = 1,hi = x;
        while(lo < hi){
            long mid = lo + (hi - lo) / 2;
            long square = mid * mid;
            if( x > square ) lo = mid+1;
            else if( x < square) hi = mid;
            else return mid;
        }
        return lo-1;
    }
};