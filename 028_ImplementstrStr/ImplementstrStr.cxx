#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

// over time limits
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        if(haystack.size() == 0) return -1;
        vector< vector<bool> > dp(haystack.size()+1, vector<bool>(needle.size()+1, false));
        for( int i = 0; i <= haystack.size(); ++i)
            dp[i][0] = true;
        for(int i = 0; i < needle.size(); ++i ){
            bool exist = false;
            for (int j = 0; j < haystack.size(); ++j){
                if( needle[i] == haystack[j] ) {
                    dp[j+1][i+1] =  dp[j][i];
                    exist = true;
                }
            }
            if(!exist) return -1;
        }
        for(int i = 1; i <= haystack.size(); ++i){
            if(dp[i][needle.size()]){
                return i-needle.size();
            }
        }
        return -1;
    }
};

// BF 暴力
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        for(int i = 0; i < n - m + 1; i ++)
        {
            int j = 0;
            for( ; j < m; j ++)
            {
                if(haystack[i + j] !=  needle[j])
                    break;
            }
            if(j == m)
                return i;
        }
        return -1;
    }
};

// sunday
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        if(haystack.size() == 0
        || haystack.size() < needle.size()) return -1;
        int m = needle.size();
        unordered_map<char, int> offset;
        for(int i=m-1; i >=0 ; --i){
            if( offset.find(needle[i]) == offset.end()){
                offset.insert({needle[i], m-i});
            }
        }

        int i = 0;
        for(; i <= haystack.size() - m; ){
            if( haystack.substr(i, m) == needle)
                return i;
            else{
                if (i+m >= haystack.size())
                    return -1;

                auto found = offset.find(haystack[i+m]);
                if(found != offset.end()){
                    i += found->second;
                }
                else{
                    i += (m + 1);
                }
            }
        }
        return  i+m < haystack.size()? i : -1;
    }
};