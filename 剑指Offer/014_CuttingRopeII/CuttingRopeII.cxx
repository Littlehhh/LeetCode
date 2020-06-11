
class Solution {
public:
    int cuttingRope(int n) {
        if(n<=3) return n-1;
        int a=n/3, b=n%3;
        int p = 1000000007;
        long rem = reminder(3, a-1, p);
        if(b==0) return (rem*3)%p;
        if(b==1) return (rem*4)%p;
        return (rem*6)%p;
    }
    long reminder(long x, int a, int p){
        long rem = 1;
        while(a>0){
            if(a&1) rem = (rem*x) %p;
            x = (x*x) % p;
            a >>= 1;
        }
        return rem;
    }
};