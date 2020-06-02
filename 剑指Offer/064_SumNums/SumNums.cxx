class Solution1 {
public:
    int sum = 0;
    int sumNums(int n) {
        n > 1 && sumNums(n-1);
        sum += n;
        return sum;
    }
};

class Solution2 {
public:
    int ans = 0;
    int sumNums(int n) {
        Multi(n, n+1);
        return ans>>1;
    }
    bool Multi(int a, int b){
        b && (b & 1) && (ans+=a); 
        b>>1 && Multi(a<<1, b>>1);
        return true;
    }
};

class Solution {
public:
    int sumNums(int n) {
        bool arr[n][n+1];
        return sizeof(arr)>>1;
    }
};