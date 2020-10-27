#include<unordered_map>
#include<string>

using namespace std;

class Solution1 {
public:
    unordered_map<string, bool> memo;
    int countBinarySubstrings(string s) {
        int n = s.size();
        
        int ans = 0;
        for(int i=0; i<n; ++i){            
            for(int j=i+1; j<n; j+=2){
                string tmp = s.substr(i,j-i+1);
                if( check( tmp ) ){
                   ans++; 
                }

            }
        }
        return ans;
    }

    bool check(string &s){
        if( memo.count(s) ) return memo[s];
        bool flag = true;
        char cur = s[0];
        for(int i=1; i<s.size()/2; ++i){
            if(cur != s[i]){
                flag = false;
                break;
            }
        }
        cur = cur=='0' ? '1' : '0';
        for(int i=s.size()/2; i<s.size(); ++i){
            if(cur != s[i]){
                flag = false;
                break;
            }
        }
        memo[s]=flag;
        return flag;
    }

};


class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int lo=0, hi=0;
        int cur = 0;
        int prev=0;
        while(hi < n){
            if(s[hi] != s[lo]){
                cur = hi-lo;
                ans+=min(prev, cur);
                prev = cur;
                lo=hi;
            }
            hi++;
        }
        if(lo < n){
            ans+=min(prev, hi-lo);
        }
        return ans;
    }
};

