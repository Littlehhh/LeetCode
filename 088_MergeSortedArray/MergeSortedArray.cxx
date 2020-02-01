#include<vector>
using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(auto && it = nums1.rbegin(); it != nums1.rend() && n>0 && m>0; ++it){
            if(nums1[m-1] > nums2[n-1]){
               *it = nums1[--m];
            }  
            else{
                *it = nums2[--n];    
            }
        }
        if(n>0){
            for(int i=0; i<n; ++i){
                nums1[i] = nums2[i];
            }
        }
    }
};