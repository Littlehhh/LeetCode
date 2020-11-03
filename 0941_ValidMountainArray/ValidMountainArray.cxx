class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int len = A.size();
        int cur = 1;
        while(cur < len && A[cur] > A[cur-1]) cur++;
        if(cur == 1 || cur == len ) return false;
        while(cur < len && A[cur] < A[cur-1]) cur++;
        return cur == len;
    }
};
static int speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
