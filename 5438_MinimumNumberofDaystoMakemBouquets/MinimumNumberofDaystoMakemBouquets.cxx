#include<vector>

using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*k > bloomDay.size()) return -1;
        if(bloomDay.size() == 0) return -1;
        int lo=1, hi = *max_element(bloomDay.begin(), bloomDay.end());
        while(lo < hi){
            int mid = lo + (hi-lo)/2;
            if(check(bloomDay, m, k,mid)){
                hi = mid;
            }
            else{
                lo=mid+1;
            }
        }
        return lo;
    }
    bool check(vector<int>& bloomDay,int m, int k, int mid){
        int cnt=0;
        int len=0;
        for(int i=0; i<bloomDay.size(); ++i ){
            if(bloomDay[i] <= mid){
                len++;
                if(len==k){
                    cnt++;
                    len=0;
                }
                
            }
            else{
                len=0;
            }
        }
        return cnt>=m;
    }
};